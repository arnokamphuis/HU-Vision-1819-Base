using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FaceRecognitionGUI
{
    public partial class TestsetManagerForm : Form
    {

        private TestSetFile oldTestSet;
        private TestSetFile currentTestSet;

        public TestsetManagerForm()
        {
            InitializeComponent();
            
        }

        private void TestsetManagerForm_Load(object sender, EventArgs e)
        {
            string testSetPath = string.Empty;
            testSetPath = ConfigManager.GetSetting("testSetPath");
            //Console.WriteLine("load ...");

             //read test set
            if (oldTestSet == null)
            {
                //Console.WriteLine("hit");
                oldTestSet = TestSetFile.readFromFile();
                currentTestSet = (TestSetFile) oldTestSet.Clone();
            }

            //display test set
            loadItemsIntoListBox();
        }

        //using this you can select a different TestSet-file
        private void browseButton_Click(object sender, EventArgs e)
        {
            FileDialog fileDialog = new OpenFileDialog();
            fileDialog.Filter = "All Types|*.*";
            fileDialog.AddExtension = true;

            Console.WriteLine("::::" + ConfigManager.GetSetting("testSetPath"));

            if (fileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                ConfigManager.UpdateSetting("testSetPath", fileDialog.FileName);
                TestsetManagerForm_Load(null, null);
                fileDialog.RestoreDirectory = true;
            }

            //loadItemsIntoListBox();
        }

        private void editButton_Click(object sender, EventArgs e)
        {
            //Changes go in the currentTestSet;
            EditTestSetDialog etsDialog = new EditTestSetDialog(currentTestSet, listBox1.SelectedIndex);

            DialogResult dialogResult = etsDialog.ShowDialog();
            if (dialogResult == DialogResult.Yes && etsDialog.getParameters() != null)
            {
                //Save changes to currentTestSet
                currentTestSet.testSets[listBox1.SelectedIndex].Name = etsDialog.getName();
                currentTestSet.testSets[listBox1.SelectedIndex].Parameters = etsDialog.getParameters();


                loadItemsIntoListBox();
            }
            else if (dialogResult == DialogResult.Abort)
            {
                //Dispose of the window
            }

            //Fill the testset-file with some data, used for testing
            /*
            TestSetFile tsf = new TestSetFile();
            tsf.testSets.Add(new TestSet("A", new double[] { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 }));
            tsf.testSets.Add(new TestSet("B", new double[] { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 }));
            tsf.testSets.Add(new TestSet("C", new double[] { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 }));
            tsf.testSets.Add(new TestSet("D", new double[] { 1, 2, 3, 4, 5, 6, 7, 8, 1, 2, 3, 4, 5, 6, 7, 8 }));
            tsf.writeToFile();
             */
        }

        private void deleteButton_Click(object sender, EventArgs e)
        {
            //Changes go in the currentTestSet;
            DialogResult dialogResult = MessageBox.Show("Weet u zeker dat u deze data wilt verwijderen?", "Verwijderen?", MessageBoxButtons.YesNo);
            if (dialogResult == DialogResult.Yes)
            {
                //Remove object from List
                currentTestSet.testSets.RemoveAt(listBox1.SelectedIndex);
                loadItemsIntoListBox();

                //Disable the buttons as nothing is selected now.
                deleteButton.Enabled = false;
                editButton.Enabled = false;
                
            }
            else if (dialogResult == DialogResult.No)
            {
                //Do nothing...
            }
        }

        private void TestsetManagerForm_FormClosing(object sender, FormClosingEventArgs e)
        {
            //before closing ask if the user wants to save changes, if they were made
            if (!oldTestSet.Equals(currentTestSet)) {
                DialogResult dialogResult = MessageBox.Show("Wijzigingen opslaan?", "Opslaan", MessageBoxButtons.YesNo);
                if (dialogResult == DialogResult.Yes)
                {
                    //Save changes to *.xml file
                    oldTestSet = (TestSetFile)currentTestSet.Clone();
                    currentTestSet.writeToFile();
                }
                else if (dialogResult == DialogResult.No)
                {
                    //Revert changes
                    currentTestSet = (TestSetFile) oldTestSet.Clone();
                }
            }
        }

        private void listBox1_SelectedValueChanged(object sender, EventArgs e)
        {
            //Selected (different) Item in listBox1

            if (listBox1.SelectedItem != null)
            {
                deleteButton.Enabled = true;
                editButton.Enabled = true;
            }
        }

        private void loadItemsIntoListBox()
        {
            //clear current list
            listBox1.Items.Clear();


            string[] itemsAsString = new string[currentTestSet.testSets.Count];

            for (int i = 0; i < currentTestSet.testSets.Count; i++)
            {
                Console.WriteLine("i: " + i);
                itemsAsString[i] = currentTestSet.testSets[i].ToString();
            }

            //convert to collection
            //string[] output = (from o in currentTestSet.testSets select o.ToString()).ToArray();
            listBox1.Items.AddRange(itemsAsString);
        }
    }
}
