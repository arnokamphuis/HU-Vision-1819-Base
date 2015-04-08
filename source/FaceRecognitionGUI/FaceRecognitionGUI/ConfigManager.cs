/*
 * Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

using System;
using System.Collections.Generic;
using System.Configuration;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace FaceRecognitionGUI
{
    public class ConfigManager
    {
        //class used for setting and retieving data from the config-file

        public static void UpdateSetting(string key, string value)
        {
            Configuration configuration = ConfigurationManager.OpenExeConfiguration(ConfigurationUserLevel.None);
            if (configuration.AppSettings.Settings[key] == null)
            {
                configuration.AppSettings.Settings.Add(key, value);
            }
            else
            {
                configuration.AppSettings.Settings[key].Value = value;
            }
            configuration.Save();//ConfigurationSaveMode.Modified);

            ConfigurationManager.RefreshSection("appSettings");
        }

        public static string GetSetting(string key)
        {
            ConfigurationManager.OpenExeConfiguration(ConfigurationUserLevel.None);

            if(ConfigurationManager.AppSettings[key] != null){
                return ConfigurationManager.AppSettings[key].ToString();
            } else{
                return null;
            }
        }

    }
}
