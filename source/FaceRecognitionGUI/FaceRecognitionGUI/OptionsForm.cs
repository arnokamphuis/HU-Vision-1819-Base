using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Configuration;

namespace FaceRecognitionGUI
{
    public partial class OptionsForm : Form
    {
        public OptionsForm()
        {
            InitializeComponent();
            loadOptions();
        }

        private void loadOptions()
        {
            bool shellUsesDefault = true;

            bool step1_1UsesDefault = true;
            bool step1_2UsesDefault = true;
            bool step1_3UsesDefault = true;
            bool step1_4UsesDefault = true;

            bool step2_1UsesDefault = true;
            bool step2_2UsesDefault = true;
            bool step2_3UsesDefault = true;
            bool step2_4UsesDefault = true;
            bool step2_5UsesDefault = true;

            bool step3_1UsesDefault = true;
            bool step3_2UsesDefault = true;
            bool step3_3UsesDefault = true;

            //attempt to retrieve all the parameters from the config-file, xxxUsesDefault is true by default
            //unless the config-file has different information.

            shellUsesDefault = ("false".Equals(ConfigManager.GetSetting("shellUsesDefault")) ? false : true);

            step1_1UsesDefault = ("false".Equals(ConfigManager.GetSetting("step1_1UsesDefault")) ? false : true);
            step1_2UsesDefault = ("false".Equals(ConfigManager.GetSetting("step1_2UsesDefault")) ? false : true);
            step1_3UsesDefault = ("false".Equals(ConfigManager.GetSetting("step1_3UsesDefault")) ? false : true);
            step1_4UsesDefault = ("false".Equals(ConfigManager.GetSetting("step1_4UsesDefault")) ? false : true);

            step2_1UsesDefault = ("false".Equals(ConfigManager.GetSetting("step2_1UsesDefault")) ? false : true);
            step2_2UsesDefault = ("false".Equals(ConfigManager.GetSetting("step2_2UsesDefault")) ? false : true);
            step2_3UsesDefault = ("false".Equals(ConfigManager.GetSetting("step2_3UsesDefault")) ? false : true);
            step2_4UsesDefault = ("false".Equals(ConfigManager.GetSetting("step2_4UsesDefault")) ? false : true);
            step2_5UsesDefault = ("false".Equals(ConfigManager.GetSetting("step2_5UsesDefault")) ? false : true);

            step3_1UsesDefault = ("false".Equals(ConfigManager.GetSetting("step3_1UsesDefault")) ? false : true);
            step3_2UsesDefault = ("false".Equals(ConfigManager.GetSetting("step3_2UsesDefault")) ? false : true);
            step3_3UsesDefault = ("false".Equals(ConfigManager.GetSetting("step3_3UsesDefault")) ? false : true);

            //ImageShells
            radioButtonShellDefault.Checked = shellUsesDefault;
            radioButtonShellStudent.Checked = !shellUsesDefault;

            //Step 1
            radioButton1D1.Checked = step1_1UsesDefault;
            radioButton1S1.Checked = !step1_1UsesDefault;

            radioButton1D2.Checked = step1_2UsesDefault;
            radioButton1S2.Checked = !step1_2UsesDefault;

            radioButton1D3.Checked = step1_3UsesDefault;
            radioButton1S3.Checked = !step1_3UsesDefault;

            radioButton1D4.Checked = step1_4UsesDefault;
            radioButton1S4.Checked = !step1_4UsesDefault;

            //Step 2
            radioButton2D1.Checked = step2_1UsesDefault;
            radioButton2S1.Checked = !step2_1UsesDefault; 
            
            radioButton2D2.Checked = step2_2UsesDefault;
            radioButton2S2.Checked = !step2_2UsesDefault;

            radioButton2D3.Checked = step2_3UsesDefault;
            radioButton2S3.Checked = !step2_3UsesDefault;

            radioButton2D4.Checked = step2_4UsesDefault;
            radioButton2S4.Checked = !step2_4UsesDefault;

            radioButton2D5.Checked = step2_5UsesDefault;
            radioButton2S5.Checked = !step2_5UsesDefault;

            //Step 3
            radioButton3D1.Checked = step3_1UsesDefault;
            radioButton3S1.Checked = !step3_1UsesDefault;

            radioButton3D2.Checked = step3_2UsesDefault;
            radioButton3S2.Checked = !step3_2UsesDefault;

            radioButton3D3.Checked = step3_3UsesDefault;
            radioButton3S3.Checked = !step3_3UsesDefault;
        
        }

        private void saveOptions()
        {
            //save all data into the config-file
            ConfigManager.UpdateSetting("shellUsesDefault", (radioButtonShellDefault.Checked == true) ? "true" : "false");

            ConfigManager.UpdateSetting("step1_1UsesDefault", (radioButton1D1.Checked == true) ? "true" : "false");
            ConfigManager.UpdateSetting("step1_2UsesDefault", (radioButton1D2.Checked == true) ? "true" : "false");
            ConfigManager.UpdateSetting("step1_3UsesDefault", (radioButton1D3.Checked == true) ? "true" : "false");
            ConfigManager.UpdateSetting("step1_4UsesDefault", (radioButton1D4.Checked == true) ? "true" : "false");

            ConfigManager.UpdateSetting("step2_1UsesDefault", (radioButton2D1.Checked == true) ? "true" : "false");
            ConfigManager.UpdateSetting("step2_2UsesDefault", (radioButton2D2.Checked == true) ? "true" : "false");
            ConfigManager.UpdateSetting("step2_3UsesDefault", (radioButton2D3.Checked == true) ? "true" : "false");
            ConfigManager.UpdateSetting("step2_4UsesDefault", (radioButton2D4.Checked == true) ? "true" : "false");
            ConfigManager.UpdateSetting("step2_5UsesDefault", (radioButton2D5.Checked == true) ? "true" : "false");

            ConfigManager.UpdateSetting("step3_1UsesDefault", (radioButton3D1.Checked == true) ? "true" : "false");
            ConfigManager.UpdateSetting("step3_2UsesDefault", (radioButton3D2.Checked == true) ? "true" : "false");
            ConfigManager.UpdateSetting("step3_3UsesDefault", (radioButton3D3.Checked == true) ? "true" : "false");
                        
        }

        private void saveButton_Click(object sender, EventArgs e)
        {
            saveOptions();
            Close();
        }

    }
}
