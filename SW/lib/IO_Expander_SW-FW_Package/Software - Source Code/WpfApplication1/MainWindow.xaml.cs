using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows;
using System.IO.Ports;
using System.Windows.Threading;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;



namespace IO_Expander_GUI
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>

    public partial class MainWindow : Window
    {
        public static byte WRITE_FLAG = 0x80;
        public static byte READ_FLAG = 0x04;

        public static byte PORT0 = 0x00;
        public static byte PORT1 = 0x40;
        public static byte PORT2 = 0x80;
        public static byte READ = 0xC0;

        public static byte ID08A = 0x00;
        public static byte ID16A = 0x08;
        public static byte ID24A = 0x10;
        public static byte ID35 = 0x18;
        
        public static byte ID39 = 0x20;
        public static byte ID54A = 0x28;
        public static byte ID54 = 0x30;
        public static byte ID38 = 0x38;

        public static byte CONFIG = 0x00;
        public static byte OUTPUT = 0x02;
        public static byte POLARITY = 0x04;
        public static byte I2C_ADDR = 0x06;
        public static byte HIGH = 0x01;
        public static byte LOW = 0x00;

        string[] high_low_source = new string[24];

        SerialPort launchpad = new SerialPort();

        byte deviceID = 0;
        
        



        public MainWindow()
        {
            
            // Build default values for input values
            for (int i = 0; i < 24;i++ )
            {
                high_low_source[i] = "H";
            }

            // Get serial ports attached to computer
            string[] ports = SerialPort.GetPortNames();
            
            // Source for combo box to define input/output
            string[] Pxx_source = { "IN", "OUT" };

            // Source for combo box to define 
            string[] device_ID = { "TCA6408A", "TCA6416A", "TCA9535/9555", "TCA9539", "TCA9554/9534", "TCA9554A/9534A", "TCA9538" };

            // Initalize XML code
            InitializeComponent();

            // Wait for XML code to instantiate
            for (int x = 0; x < 100000; x++) ;

            // Set Source for DeviceSelection Combobox
            DeviceSelection.ItemsSource = device_ID;

            deviceID = ID39;

            // Set source for Com port selection combo box
            com_port_Combo.ItemsSource = ports;

            // Set source for Input/output selection on each valid port
            p00_In_Out.ItemsSource = Pxx_source;
            p01_In_Out.ItemsSource = Pxx_source;
            p04_In_Out.ItemsSource = Pxx_source;
            p05_In_Out.ItemsSource = Pxx_source;
            p06_In_Out.ItemsSource = Pxx_source;
            p07_In_Out.ItemsSource = Pxx_source;
            p10_In_Out.ItemsSource = Pxx_source;
            p11_In_Out.ItemsSource = Pxx_source;
            p12_In_Out.ItemsSource = Pxx_source;
            p13_In_Out.ItemsSource = Pxx_source;
            p14_In_Out.ItemsSource = Pxx_source;
            p15_In_Out.ItemsSource = Pxx_source;
            p16_In_Out.ItemsSource = Pxx_source;
            p17_In_Out.ItemsSource = Pxx_source;

            // Set source for Input/output selection on each valid port
            p00_24A.ItemsSource = Pxx_source;
            p01_24A.ItemsSource = Pxx_source;
            //p02_24A.ItemsSource = Pxx_source; //P02 on TCA6424A is hardwired to an LED (output configuration)
            //p03_24A.ItemsSource = Pxx_source; //P03 on TCA6424A is hardwired to an LED (output configuration)
            p04_24A.ItemsSource = Pxx_source;
            p05_24A.ItemsSource = Pxx_source;
            p06_24A.ItemsSource = Pxx_source;
            p07_24A.ItemsSource = Pxx_source;

            p10_24A.ItemsSource = Pxx_source;
            p11_24A.ItemsSource = Pxx_source;
            p12_24A.ItemsSource = Pxx_source;
            p13_24A.ItemsSource = Pxx_source;
            p14_24A.ItemsSource = Pxx_source;
            p15_24A.ItemsSource = Pxx_source;
            p16_24A.ItemsSource = Pxx_source;
            p17_24A.ItemsSource = Pxx_source;

            p20_24A.ItemsSource = Pxx_source;
            p21_24A.ItemsSource = Pxx_source;
            p22_24A.ItemsSource = Pxx_source;
            p23_24A.ItemsSource = Pxx_source;
            p24_24A.ItemsSource = Pxx_source;
            p25_24A.ItemsSource = Pxx_source;
            p26_24A.ItemsSource = Pxx_source;
            p27_24A.ItemsSource = Pxx_source;
                        
        }

        private void click_exit(object sender, RoutedEventArgs e)
        {
            // Close launchpad port if able
            try
            {
                launchpad.Close();
            }
            catch (System.IO.IOException c) { }
        }
        

        private void com_Selected(object sender, RoutedEventArgs e)
        {
            ComboBox local = sender as ComboBox;
            
            // Open comport using 9600 baud 8 bits, 1 stop bit, no parity with comport selected com port name
            launchpad.PortName = (string)com_port_Combo.SelectedItem;
            
            launchpad.StopBits = StopBits.One;
            launchpad.Parity = Parity.None;
            launchpad.DataBits = 8;
            launchpad.BaudRate  =  9600;
            launchpad.WriteTimeout = 500;

            // Attempt to open com port
            try
            {
                launchpad.Open();
            }
            // Catch exception if open fails
            catch (System.IO.IOException g)
            {
                MessageBox.Show("Com port fail please un-plug and plug LaunchPad back in" + " " + g.Message);
                
                // Remove event handler so that when the combo box index is changed to un selected, another event is not raised
                local.SelectionChanged -= com_Selected;
                // Unselect com port
                local.SelectedIndex = -1;
                // Re-attach event handler
                local.SelectionChanged += com_Selected;
            }
            // Create new event handler for recieved serial data
            launchpad.DataReceived += new SerialDataReceivedEventHandler(launchpad_DataReceived);

        }

        // Event handler that is called on hover over com port combo box
        // Will regenerate list of ports
        private void reload_COM(object sender, EventArgs e)
        {   
            string[] ports = SerialPort.GetPortNames();
            com_port_Combo.ItemsSource = ports;
        }

        // Event handler for serial data recieved
        private void launchpad_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            
            // Generate input buffer to store incoming bytes
            byte[] input_buffer = new byte[100];

            // Read flag byte
            input_buffer[0] = (byte)launchpad.ReadByte();

            // Only one more byte to follow
            if (input_buffer[0] == 0xFE || input_buffer[0] == 0x40)
                input_buffer[1] = (byte)launchpad.ReadByte();

            
            if (input_buffer[0] == 0xEC)
            {
                input_buffer[1] = (byte)launchpad.ReadByte();
                while(launchpad.BytesToRead < input_buffer[1]);
                launchpad.Read(input_buffer, 2, input_buffer[1]);
            }

            if (input_buffer[0] == 0xDE)
            {
                while (launchpad.BytesToRead < 3) ;
                launchpad.Read(input_buffer, 1, 3);
            }
            if (input_buffer[0] == 0xDF)
            {
                while (launchpad.BytesToRead < 2) ;
                launchpad.Read(input_buffer, 1, 2);
            }


            launchpad.DiscardInBuffer();

            // Invoke thread with GUI permissions to update GUI for recieved input data
            Dispatcher.Invoke(DispatcherPriority.Send, new UpdateReady(UI_update), input_buffer);
        }
        private void UI_update(byte[] input)
        {    
             if (input[0] == 0xDE)
            {
                    Byte_TO_string(input[1]);
                    p00_24A_in.Content = high_low_source[0];
                    p01_24A_in.Content = high_low_source[1];
                    //p02_24A_in.Content = high_low_source[2]; //P02 on TCA6424A is hardwired to an LED (output configuration)
                    //p03_24A_in.Content = high_low_source[3]; //P03 on TCA6424A is hardwired to an LED (output configuration)
                    p04_24A_in.Content = high_low_source[4];
                    p05_24A_in.Content = high_low_source[5];
                    p06_24A_in.Content = high_low_source[6];
                    p07_24A_in.Content = high_low_source[7];

                    Byte_TO_string(input[2]);
                    p10_24A_in.Content = high_low_source[0];
                    p11_24A_in.Content = high_low_source[1];
                    p12_24A_in.Content = high_low_source[2];
                    p13_24A_in.Content = high_low_source[3];
                    p14_24A_in.Content = high_low_source[4];
                    p15_24A_in.Content = high_low_source[5];
                    p16_24A_in.Content = high_low_source[6];
                    p17_24A_in.Content = high_low_source[7];

                    Byte_TO_string(input[3]);
                    p20_24A_in.Content = high_low_source[0];
                    p21_24A_in.Content = high_low_source[1];
                    p22_24A_in.Content = high_low_source[2];
                    p23_24A_in.Content = high_low_source[3];
                    p24_24A_in.Content = high_low_source[4];
                    p25_24A_in.Content = high_low_source[5];
                    p26_24A_in.Content = high_low_source[6];
                    p27_24A_in.Content = high_low_source[7];
                
            }
             if (input[0] == 0xDF)
             {
                 Byte_TO_string(input[1]);
                 p00_in.Content = high_low_source[0];
                 p01_in.Content = high_low_source[1];
                 p04_in.Content = high_low_source[4];
                 p05_in.Content = high_low_source[5];
                 p06_in.Content = high_low_source[6];
                 p07_in.Content = high_low_source[7];

                 Byte_TO_string(input[2]);
                 p10_in.Content = high_low_source[0];
                 p11_in.Content = high_low_source[1];
                 p12_in.Content = high_low_source[2];
                 p13_in.Content = high_low_source[3];
                 p14_in.Content = high_low_source[4];
                 p15_in.Content = high_low_source[5];
                 p16_in.Content = high_low_source[6];
                 p17_in.Content = high_low_source[7];


             }
            if (input[0] == 0xF1)
            {
                noDevice_label.Visibility = Visibility.Visible;
            }

        }
        
        private void Window_Closing(object sender, System.ComponentModel.CancelEventArgs e)
        {
            try
            {
                launchpad.Close();
            }
            catch (System.IO.IOException c) { }
        }

        private void in_out_change(object sender, SelectionChangedEventArgs e)
        {
            ComboBox local = sender as ComboBox;

            string temp = (string)local.SelectedValue;
            byte[] serial_buffer = new byte[2];
            if (string.Equals(temp, "IN"))
            {
                switch (local.Name)
                {
                    case "p00_In_Out":
                            serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x01;
                        break;
                    case "p01_In_Out":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x02;
                        break;
                    case "p04_In_Out":
                       serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x10;
                        break;
                    case "p05_In_Out":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + HIGH);
                        serial_buffer[1] = 0x20;
                        break;
                    case "p06_In_Out":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + HIGH);
                        serial_buffer[1] = 0x40;
                        break;
                    case "p07_In_Out":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + HIGH);
                        serial_buffer[1] = 0x80;
                        break;
                    case "p10_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x01;
                        break;
                    case "p11_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x02;
                        break;

                    case "p12_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x04;
                        break;

                    case "p13_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x08;
                        break;

                    case "p14_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x10;
                        break;
                    case "p15_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x20;
                        break;
                    case "p16_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x40;
                        break;
                    case "p17_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + HIGH);
                            serial_buffer[1] = 0x80;
                        break;


                    case "p00_24A":
                            serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x01;
                            break;
                    case "p01_24A":
                            serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x02;
                            break;
                    case "p02_24A":
                            serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x04;
                            break;
                    case "p03_24A":
                            serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x08;
                            break;
                    case "p04_24A":
                            serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x10;
                            break;
                    case "p05_24A":
                            serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x20;
                            break;
                    case "p06_24A":
                            serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x40;
                            break;
                    case "p07_24A":
                            serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x80;
                            break;

                    case "p10_24A":
                            serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x01;
                            break;
                    case "p11_24A":
                            serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x02;
                            break;
                    case "p12_24A":
                            serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x04;
                            break;
                    case "p13_24A":
                            serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x08;
                            break;
                    case "p14_24A":
                            serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x10;
                            break;
                    case "p15_24A":
                            serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x20;
                            break;
                    case "p16_24A":
                            serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x40;
                            break;
                    case "p17_24A":
                            serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x80;
                            break;

                    case "p20_24A":
                            serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x01;
                            break;
                    case "p21_24A":
                            serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x02;
                            break;
                    case "p22_24A":
                            serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x04;
                            break;
                    case "p23_24A":
                            serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x08;
                            break;
                    case "p24_24A":
                            serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x10;
                            break;
                    case "p25_24A":
                            serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x20;
                            break;
                    case "p26_24A":
                            serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x40;
                            break;
                    case "p27_24A":
                            serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + HIGH);
                            serial_buffer[1] = 0x80;
                            break;

                    default: break;
                }
                
            }
            if (string.Equals(temp, "OUT"))
            {
                switch (local.Name)
                {
                    case "p00_In_Out":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x01;
                        break;
                    case "p01_In_Out":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x02;
                        break;
                    case "p04_In_Out":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x10;
                        break;
                    case "p05_In_Out":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x20;
                        break;
                    case "p06_In_Out":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x40;
                        break;
                    case "p07_In_Out":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x80;
                        break;
                    case "p10_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x01;
                        break;
                    case "p11_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x02;
                        break;

                    case "p12_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x04;
                        break;

                    case "p13_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x08;
                        break;

                    case "p14_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x10;
                        break;
                    case "p15_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x20;
                        break;
                    case "p16_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x40;
                        break;
                    case "p17_In_Out":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + deviceID + LOW);
                        serial_buffer[1] = 0x80;
                        break;



                    case "p00_24A":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x01;
                        break;
                    case "p01_24A":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x02;
                        break;
                    case "p02_24A":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x04;
                        break;
                    case "p03_24A":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x08;
                        break;
                    case "p04_24A":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x10;
                        break;
                    case "p05_24A":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x20;
                        break;
                    case "p06_24A":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x40;
                        break;
                    case "p07_24A":
                        serial_buffer[0] = (byte)(PORT0 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x80;
                        break;

                    case "p10_24A":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x01;
                        break;
                    case "p11_24A":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x02;
                        break;
                    case "p12_24A":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x04;
                        break;
                    case "p13_24A":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x08;
                        break;
                    case "p14_24A":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x10;
                        break;
                    case "p15_24A":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x20;
                        break;
                    case "p16_24A":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x40;
                        break;
                    case "p17_24A":
                        serial_buffer[0] = (byte)(PORT1 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x80;
                        break;

                    case "p20_24A":
                        serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x01;
                        break;
                    case "p21_24A":
                        serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x02;
                        break;
                    case "p22_24A":
                        serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x04;
                        break;
                    case "p23_24A":
                        serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x08;
                        break;
                    case "p24_24A":
                        serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x10;
                        break;
                    case "p25_24A":
                        serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x20;
                        break;
                    case "p26_24A":
                        serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x40;
                        break;
                    case "p27_24A":
                        serial_buffer[0] = (byte)(PORT2 + CONFIG + 0x10 + LOW);
                        serial_buffer[1] = 0x80;
                        break;

                    default: break;

                    
                }

            }
            if (launchpad.IsOpen)
            {
                try
                {
                    launchpad.Write(serial_buffer, 0, 2);
                }
                catch (Exception ex) 
                {
                    if(ex is ArgumentNullException || ex is ArgumentOutOfRangeException || ex is TimeoutException)
                    {
                        return;
                    }
                    throw;

                }
            }
        }


        private void pxx_checkx_Click(object sender, RoutedEventArgs e)
        {
            CheckBox local = sender as CheckBox;
            byte[] serial_buffer = new byte[2];
            if (!local.Name.Contains("24A"))
            {
                switch (local.Name)
                {
                    //------------Port0 Output--------------------------------------------------
                    case "p00_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x01;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x01;
                        }
                        break;
                    case "p01_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x02;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x02;
                        }
                        break;
                    case "p02_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x04;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x04;
                        }
                        break;
                    case "p03_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x08;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x08;
                        }
                        break;
                    case "p04_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x10;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x10;
                        }
                        break;
                    case "p05_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x20;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x20;
                        }
                        break;
                    case "p06_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x40;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x40;
                        }
                        break;
                    case "p07_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x80;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x80;
                        }
                        break;

                    //------------Port0 Polarity--------------------------------------------------
                    case "p00_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x01;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x01;
                        }
                        break;
                    case "p01_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x02;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x02;
                        }
                        break;
                    case "p04_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x10;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x10;
                        }
                        break;
                    
                     case "p05_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x20;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x20;
                        }
                        break;
                     case "p06_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x40;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x40;
                        }
                        break;
                     case "p07_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x80;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT0 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x80;
                        }
                        break;
                     
                     
                    //------------Port1 Output--------------------------------------------------
                    case "p10_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x01;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x01;
                        }
                        break;
                    case "p11_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x02;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x02;
                        }
                        break;
                    case "p12_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x04;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x04;
                        }
                        break;
                    case "p13_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x08;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x08;
                        }
                        break;
                    case "p14_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x10;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x10;
                        }
                        break;
                    case "p15_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x20;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x20;
                        }
                        break;
                    case "p16_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x40;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x40;
                        }
                        break;
                    case "p17_Output":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + HIGH);
                            serial_buffer[1] = 0x80;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + OUTPUT + deviceID + LOW);
                            serial_buffer[1] = 0x80;
                        }
                        break;
                    //------------Port1 Polarity---------------------------------------------------
                    case "p10_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x01;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x01;
                        }
                        break;
                    case "p11_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x02;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x02;
                        }
                        break;
                    case "p12_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x04;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x04;
                        }
                        break;
                    case "p13_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x08;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x08;
                        }
                        break;
                    case "p14_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x10;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x10;
                        }
                        break;
                    case "p15_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x20;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x20;
                        }
                        break;
                    case "p16_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x40;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x40;
                        }
                        break;
                    case "p17_Polarity":
                        if (local.IsChecked == true)
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + HIGH);
                            serial_buffer[1] = 0x80;
                        }
                        else
                        {
                            serial_buffer[0] = (byte)(PORT1 + POLARITY + deviceID + LOW);
                            serial_buffer[1] = 0x80;
                        }
                        break;
                    default: break;





                }
            }                
            else 
            {
                    serial_buffer[0] = 0x10;
                    if(local.Name.Contains("p0"))
                    {
                        serial_buffer[0] += (byte)PORT0;
                    }
                    else if (local.Name.Contains("p1"))
                    {
                        serial_buffer[0] += (byte)PORT1;
                    }
                    else if (local.Name.Contains("p2"))
                    {
                        serial_buffer[0] += (byte)PORT2;
                    }
                    if (local.Name.Contains("out"))
                    {
                        serial_buffer[0] += (byte)OUTPUT;
                    }
                    else if (local.Name.Contains("pol"))
                    {
                        serial_buffer[0] += (byte)POLARITY;
                    }

                    if (local.IsChecked == true)
                    {
                        serial_buffer[0] += 0x01;
                    }

                    int leftshift = int.Parse(local.Name.Substring(2,1));
                    serial_buffer[1] = (byte)(0x01 << leftshift);

            }
            if (launchpad.IsOpen)
            {
                try
                {
                    launchpad.Write(serial_buffer, 0, 2);
                }
                catch (Exception ex)
                {
                    if (ex is ArgumentNullException || ex is ArgumentOutOfRangeException || ex is TimeoutException)
                    {
                        return;
                    }
                    throw;

                }
            }
        }



       


        private void button2_Click(object sender, RoutedEventArgs e)
        {
            Button local = sender as Button;
            byte[] ser_buffer = new byte[1];
            if(local.Content.ToString() == "Demo On")
            {
                local.Content = "Demo Off";
                ser_buffer[0] = 0xBC;
            }
            else
            {
                local.Content = "Demo On";
                ser_buffer[0] = 0xBE;
            }
            if (launchpad.IsOpen)
            {
                try
                {
                    launchpad.Write(ser_buffer, 0, 1);
                }
                catch (Exception ex)
                {
                    if (ex is ArgumentNullException || ex is ArgumentOutOfRangeException || ex is TimeoutException)
                    {
                        return;
                    }
                    throw;

                }
            }
        }

        private void DeviceSelection_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            noDevice_label.Visibility = Visibility.Hidden;
            byte[] ser_buffer = new byte[2];
            switch (DeviceSelection.SelectedItem.ToString())
            {
                case "TCA6408A":
                    deviceID = ID08A;
                    break;
                case "TCA6416A":
                    deviceID = ID16A;
                    break;
                case "TCA9535/9555":
                    deviceID = ID35;
                    break;
                case "TCA9538":
                    deviceID = ID38;
                    break;
                case "TCA9539":
                    deviceID = ID39;
                    break;
                case "TCA9554/9534":
                    deviceID = ID54;
                    break;
                case "TCA9554A/9534A":
                    deviceID = ID54A;
                    break;


            } 
            ser_buffer[0] = (byte)(READ + deviceID + HIGH);
            ser_buffer[1] = 0;
            if (launchpad.IsOpen)
            {
                try
                {
                    launchpad.Write(ser_buffer, 0, 2);
                }
                catch (Exception ex)
                {
                    if (ex is ArgumentNullException || ex is ArgumentOutOfRangeException || ex is TimeoutException)
                    {
                        return;
                    }
                    throw;

                }
            }
        }



        private void Byte_TO_string(byte pass)
        {
            for (int i = 0; i < 8; i++)
            {
                
                if ((pass & 0x01) == 0x01)
                    high_low_source[i] = "H";
                else
                    high_low_source[i] = "L";

                pass = (byte)(pass >> 1);
            }

        }

    }


    
    public static class Extensions
    {
        public static RadioButton SelectedRadioButton(this GroupBox g)
        {
            Grid temp = (Grid)g.Content;
            UIElementCollection whats = temp.Children;
            return whats.OfType<RadioButton>().Where(rb => (bool)rb.IsChecked).FirstOrDefault();
        }
        public static ComboBox parentCombo(this RadioButton g)
        {
            if (g != null)
            {
                Grid temp = (Grid)g.Parent;
                UIElementCollection whats = temp.Children;
                return whats.OfType<ComboBox>().Where(cb => (bool)(cb.Name == g.GroupName + "combo")).FirstOrDefault();
            }
            return null;
        }
    }

    public class visibilityMultiConverter : IMultiValueConverter
    {
        #region IMultiValueConverter Members

        public object Convert(object[] values, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            int Device = (int)values[0];
            int in_out = (int)values[1];
            string type = parameter as string;

                    if (Device == 0 || Device == 4 || Device == 5 || Device == 6)
                    {
                        return Visibility.Hidden;
                    }
                    else
                    {
                        if (type != "Polarity")
                        {
                            if (in_out == 0)
                                return Visibility.Hidden;
                            else
                                return Visibility.Visible;
                        }
                        else
                        {
                            if (in_out == 1)
                                return Visibility.Hidden;
                            else
                                return Visibility.Visible;
                        }
                    }


        }





        public object[] ConvertBack(object value, Type[] targetTypes, object parameter, System.Globalization.CultureInfo culture)
        {
            return null;

        }

        #endregion
    }

    public class visibilityMultiConverterNOT : IMultiValueConverter
    {
        #region IMultiValueConverter Members

        public object Convert(object[] values, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            int Device = (int)values[0];
            int in_out = (int)values[1];
            string type = parameter as string;

            if (!(Device == 0 || Device == 4 || Device == 5 || Device == 6))
            {
                return Visibility.Hidden;
            }
            else
            {
                if (type != "Polarity")
                {
                    if (in_out == 0)
                        return Visibility.Hidden;
                    else
                        return Visibility.Visible;
                }
                else
                {
                    if (in_out == 1)
                        return Visibility.Hidden;
                    else
                        return Visibility.Visible;
                }
            }


        }





        public object[] ConvertBack(object value, Type[] targetTypes, object parameter, System.Globalization.CultureInfo culture)
        {
            return null;

        }

        #endregion
    }


    public class visibilityConverter : IValueConverter
    {
        #region IValueConverter Members

        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string local = (string)value;

            if (local == "OFF" || local == "ON" || local == "OUT" || local == "TCA6408A" || local == "TCA9554A/9534A" || local == "TCA9554/9534" || local == "TCA9538")
                    return Visibility.Hidden;
                else
                    return Visibility.Visible;

        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            return null;
        }
        #endregion
    }

    public class visibilityConverterNOT : IValueConverter
    {
        #region IValueConverter Members

        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string local = (string)value;

            if (local == "TCA6408A" || local == "TCA9554A/9534A" || local == "TCA9554/9534" || local == "TCA9538")
                return Visibility.Visible;
            else
                return Visibility.Hidden;

        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            return null;
        }
        #endregion
    }

    public class visibilitySlideConverter : IValueConverter
    {
        #region IValueConverter Members

        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            string local = (string)value;

            if (local == "IN")
                return Visibility.Hidden;
            else
                return Visibility.Visible;

        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            return null;
        }
        #endregion
    }
    public class enableConverter : IValueConverter
    {
        #region IValueConverter Members

        public object Convert(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            Visibility local = (Visibility)value;
            
            if (local == Visibility.Visible)
                return false;
            else
                return true;

        }

        public object ConvertBack(object value, Type targetType, object parameter, System.Globalization.CultureInfo culture)
        {
            return null;
        }
        #endregion

    }

    public delegate void UpdateReady(byte[] input);
    

}
