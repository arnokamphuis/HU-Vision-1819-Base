/*
 * Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

using System;
using System.Collections.Generic;
using System.Configuration;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace FaceRecognitionGUI
{
    [XmlRoot("TestSetFile")]
    public class TestSetFile
    {
        //class used to read and write data with the default XML parser
        //also contains methods to compare and copy the data


        public object Clone()
        {
            TestSetFile tsf = (TestSetFile)this.MemberwiseClone();

            tsf.testSets = new List<TestSet>();
            foreach (TestSet ts in testSets)
            {
                tsf.testSets.Add((TestSet)ts.Clone());
            }

            return tsf;
        }

        public override bool Equals(Object obj)
        {
            if (obj == null)  return false;

            // If parameter cannot be cast to Point return false.
            TestSetFile p = obj as TestSetFile;
            if ((System.Object)p == null) return false;

            // Return true if the fields match:
            if (p.testSets.Count != testSets.Count) return false;

            for (int i = 0; i < testSets.Count; i++)
            {
                if (!testSets[i].Equals(p.testSets[i])) return false;
            }

            return true;
        }

        [XmlElement(ElementName = "name")]
        public List<TestSet> testSets = new List<TestSet>();

        public void writeToFile()
        {
            string path = "";
            XmlSerializer serializer = new XmlSerializer(typeof(TestSetFile));
            if (ConfigurationManager.AppSettings["testSetPath"] == null)
            {
                path = "TestSet.xml";
            }
            else
            {
                path = ConfigurationManager.AppSettings["testSetPath"].ToString();
            }
            TextWriter writer = new StreamWriter(path);
            serializer.Serialize(writer, this);
            writer.Close();
        }

        public static TestSetFile readFromFile()
        {
            XmlSerializer serializer = new XmlSerializer(typeof(TestSetFile));

            string path = "";
            if (ConfigurationManager.AppSettings["testSetPath"] == null || ConfigurationManager.AppSettings["testSetPath"].ToString() == "")
            {
                path = "TestSet.xml";
                ConfigurationManager.AppSettings["testSetPath"] = path;
            }
            else
            {
                path = ConfigurationManager.AppSettings["testSetPath"].ToString();
            }

            if (!File.Exists(path))
            {
                createFile(path);
            }
            FileStream fs = new FileStream(path, FileMode.Open);

            TestSetFile temp = (TestSetFile)serializer.Deserialize(fs);
            fs.Close();

            return temp;
        }

        private static void createFile(string path)
        {
            using (StreamWriter sw = File.CreateText(path)) 
            {
                sw.WriteLine("<?xml version=\"1.0\" encoding=\"utf-8\"?>");
                sw.WriteLine("<TestSetFile xmlns:xsi=\"http://www.w3.org/2001/XMLSchema-instance\" xmlns:xsd=\"http://www.w3.org/2001/XMLSchema\">");
                sw.WriteLine("</TestSetFile>");
            }	
        }
    }


    public class TestSet
    {
        public object Clone()
        {
            TestSet ts = (TestSet) this.MemberwiseClone();
            
            //Name
            ts.Name = this.Name;
            
            //Parameters
            for (int i = 0; i < 16; i++)
            {
                ts.Parameters[i] = this.Parameters[i];
            }

            //ImagePath
            ts.ImagePath = this.ImagePath;

            return ts;
        }

        public override bool Equals(object obj)
        {
            if (obj == null)    return false;

            // If parameter cannot be cast to TestSet return false.
            TestSet p = obj as TestSet;
            if ((System.Object)p == null) return false;

            // Return true if the fields match:
            if (!p.Name.Equals(this.Name)) return false;
            for (int i = 0; i < 16; i++) 
            {
                if (p.Parameters[i] != (this.Parameters[i])) return false;
            }

            if (!p.ImagePath.Equals(this.ImagePath)) return false;

            return true;
        }

        [XmlAttribute]
        public string Name;

        [XmlArrayAttribute("Parameters", IsNullable = false)]
        public double[] Parameters = new double[16];

        [XmlAttribute]
        public string ImagePath;

        public TestSet()
        {

        }

        public TestSet(string name, double[] parameters, string imagePath)
        {
            Name = name;
            for (int i = 0; i < 16; i++) {
                Parameters[i] = parameters[i];
            }
            Console.WriteLine("Params:" + Parameters == null);

            ImagePath = imagePath;
        }

        public override String ToString()
        {
            return "Name: " + Name + "; Parameters: {" + String.Join(";", Parameters.Select(p => p.ToString())) + "}; ImagePath: " + ImagePath;
        }
    }

}