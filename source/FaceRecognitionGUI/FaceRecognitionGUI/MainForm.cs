/*
 * Copyright (c) 2015 DottedEye Designs, Alexander Hustinx, NeoTech Software, Rolf Smit - All Rights Reserved
 * Unauthorized copying of this file, via any medium is strictly prohibited
 * Proprietary and confidential
 */

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Configuration;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Xml;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FaceRecognitionGUI
{
    public partial class MainForm : Form
    {
        private TestsetManagerForm tmForm;
        private OptionsForm oForm;

        public MainForm()
        {
            InitializeComponent();
            CheckForIllegalCrossThreadCalls = false;
            feedbackTextBox.ScrollBars = ScrollBars.Vertical;
        }

        private void executeButton_Click(object sender, EventArgs e)
        {

            //clear picture boxes and console
            pictureBox2.Image = null;
            pictureBox3.Image = null;
            pictureBox4.Image = null;
            pictureBox5.Image = null;
            resultPictureBox.Image = null;

            //clear console
            feedbackTextBox.Clear();

            if (scanRadioButton.Checked == true)
            {
                //Adding face to testset 
                Console.WriteLine("Uitvoeren ingedrukt -> Gezicht inscannen van " + (nameTextBox.Text==""?"<unknown>":nameTextBox.Text) + ".");
            }
            else if (recognizeRadioButton.Checked == true)
            {
                //Recognising face
                Console.WriteLine("Uitvoeren ingedrukt -> Gezicht herkennen.");
            }
            else if (sequenceRadioButton.Checked == true)
            {
                //Recognising sequence of faces
                Console.WriteLine("Uitvoeren ingedrukt -> Sequentie gezichten herkennen. (xml: " + sequenceTextBox.Text + ")");
            }
            else
            {
                //Do nothing ...
                Console.WriteLine("Uitvoeren ingedrukt -> Selecteer uitvoerwijze!");
                return;
            }

            if (mainPictureBox.Image == null)
            {
                if (sequenceRadioButton.Checked == true)
                {
                    log("Meerdere afbeeldingen worden ingeladen uit de xml-file.");
                }
                else
                {
                    log("Er moet een afbeelding geselecteerd worden in de mainPictureBox!");
                    return;
                }
            }

            //Only run the program when it isn't still busy
            if (backgroundWorker.IsBusy == false) 
            {
                backgroundWorker.RunWorkerAsync();
            }
        }

        private double[] doFaceRecognitionTask(Image image)
        {
            //retrieve from the Config-file if the student image shell should be used (if not set, use default)
            FaceRecognitionTask.setImageImplementation(("false".Equals(ConfigManager.GetSetting("shellUsesDefault")) ? true : false));
            FaceRecognitionTask task = new FaceRecognitionTask(new Bitmap(image));
     

            try {
                doPreProcessing(task);

                doLocalization(task);

                doExtraction(task);

                if (!task.executePostProcessing()) {
                    throw new FaceRecognitionTask.FaceRecognitionException("Post-processing: failed!");
                }

                if (!task.executeRepresentation()) {
                    throw new FaceRecognitionTask.FaceRecognitionException("Representation: failed!");
                } else {
                    return task.getFacialParameters();
                }
            } catch (FaceRecognitionTask.FaceRecognitionException e) {
                log("Exception during face recognition:");
                log(e.Message);
            } finally {
                task.dispose();
            }
            return null;
        }

        private void doExtraction(FaceRecognitionTask task) {
           task.prepareExtraction();
           //retrieve from the Config-file if the student algorithms should be used (if not set, use default)
            
            task.executeExtractionStep1(("false".Equals(ConfigManager.GetSetting("step3_1UsesDefault")) ? true : false ));
            log("Extraction step 1: successful!");
            pictureBox5.Image = task.extractionDebug;
          
            
            task.executeExtractionStep2(("false".Equals(ConfigManager.GetSetting("step3_2UsesDefault")) ? true : false ));
            log("Extraction step 2: successful!");
            pictureBox5.Image = task.extractionDebug;
          

            task.executeExtractionStep3(("false".Equals(ConfigManager.GetSetting("step3_3UsesDefault")) ? true : false ));
            log("Extraction step 3: successful!");
            pictureBox5.Image = task.extractionDebug;
        }

        private void doLocalization(FaceRecognitionTask task) {
            task.prepareLocalization();
            //retrieve from the Config-file if the student algorithms should be used (if not set, use default)

            task.executeLocalizationStep1(("false".Equals(ConfigManager.GetSetting("step2_1UsesDefault")) ? true : false));
            log("Localization step 1: successful!");
            pictureBox4.Image = task.localizationDebug;

            task.executeLocalizationStep2(("false".Equals(ConfigManager.GetSetting("step2_2UsesDefault")) ? true : false ));
            log("Localization step 2: successful!");
            pictureBox4.Image = task.localizationDebug;
            
            task.executeLocalizationStep3(("false".Equals(ConfigManager.GetSetting("step2_3UsesDefault")) ? true : false));
            log("Localization step 3: successful!");
            pictureBox4.Image = task.localizationDebug;
           

            task.executeLocalizationStep4(("false".Equals(ConfigManager.GetSetting("step2_4UsesDefault")) ? true : false));
            log("Localization step 4: successful!");
            pictureBox4.Image = task.localizationDebug;
            
            task.executeLocalizationStep5(("false".Equals(ConfigManager.GetSetting("step2_5UsesDefault")) ? true : false ));
            log("Localization step 5: successful!");
            pictureBox4.Image = task.localizationDebug;
            
        }

        private void doPreProcessing(FaceRecognitionTask task) {
            //retrieve from the Config-file if the student algorithms should be used (if not set, use default)

            task.executePreProcessingStep1(("false".Equals(ConfigManager.GetSetting("step1_1UsesDefault")) ? true : false));
            log("PreProcessing step 1: successful!");

            task.executePreProcessingStep2(("false".Equals(ConfigManager.GetSetting("step1_2UsesDefault")) ? true : false));
            log("PreProcessing step 2: successful!");
            pictureBox2.Image = task.preProcessing2;

            task.executePreProcessingStep3(("false".Equals(ConfigManager.GetSetting("step1_3UsesDefault")) ? true : false));
            log("PreProcessing step 3: successful!");

            task.executePreProcessingStep4(("false".Equals(ConfigManager.GetSetting("step1_4UsesDefault")) ? true : false));
            log("PreProcessing step 4: successful!");
            pictureBox3.Image = task.preProcessing4;
        }


        private void mainPictureBox_DoubleClick(object sender, EventArgs e)
        {
            //On double click open the file dialog to select an image
            if (((MouseEventArgs)e).Button == System.Windows.Forms.MouseButtons.Left)   //Ugly cast to MouseEventArgs, but it works so YOLO.
            {
                Console.WriteLine("mainPictureBox_DoubleClick(Left)");

                openImageWithFileDialog(mainPictureBox);
            }
        }

        private void backgroundWorker_DoWork(object sender, DoWorkEventArgs e)
        {
            log("Uitvoeren begonnen ...");

            toolStripStatusLabel2.Text = "Bezig ...";

            //When executing the program on a sequence of images, read the given xml-file and retreive the image paths 
            if (sequenceRadioButton.Checked == true)
            {
                List<string> paths = new List<string>();
                XmlTextReader reader = new XmlTextReader(sequenceTextBox.Text);
                while (reader.Read())
                {
                    switch (reader.NodeType)
                    {
                        case XmlNodeType.Text:
                            log("" + reader.Value);
                            paths.Add(reader.Value);
                            break;

                        default:
                            break;
                    }
                }               
                
                for (int i = 0; i < paths.Count; i++)
                {
                    //read filename/path from xml
                    mainPictureBox.ImageLocation = paths[i];
                    mainPictureBox.Image = new Bitmap(paths[i]);
                    executeFaceRecognition();
                }
            }
            //When not executing the program on a sequence of images, execute normally
            else
            {
                executeFaceRecognition();
            }
        }

        private void backgroundWorker_RunWorkerCompleted(object sender, RunWorkerCompletedEventArgs e)
        {
            //When finished ...
            toolStripStatusLabel2.Text = "Klaar.";
        }

        private void executeFaceRecognition()
        {
            //array containing the 16 facial parameters resulting from the program
            double[] facialParamters = doFaceRecognitionTask(mainPictureBox.Image);

            //When the algorithm is unsuccesful, the facial parameters can be null
            if (facialParamters != null)
            {
                //Gezicht inscannen
                if (scanRadioButton.Checked == true)
                {
                    //retrieve the TestSet-file location, if it doesn't exist create it and save the (new) path in the config-file
                    if ((ConfigManager.GetSetting("testSetPath") != null || ConfigManager.GetSetting("testSetPath") != ""))
                    {
                        TestSetFile tsf = TestSetFile.readFromFile();
                        string imgPath = saveImageToTestSetDir(mainPictureBox.Image, (nameTextBox.Text == "" ? "<unknown>" : nameTextBox.Text));
                        tsf.testSets.Add(new TestSet((nameTextBox.Text == "" ? "<unknown>" : nameTextBox.Text), facialParamters, imgPath));
                        tsf.writeToFile();

                        log(imgPath);
                        log("inscannen succesvol.");
                    }
                }

                //Gezicht vergelijken
                else if (recognizeRadioButton.Checked == true || sequenceRadioButton.Checked == true)
                {
                    //retrieve the TestSet-file location form the config-file, if it doesn't exist do nothing
                    if ((ConfigManager.GetSetting("testSetPath") != null || ConfigManager.GetSetting("testSetPath") != ""))
                    {
                        string bestMatchName = "";
                        double bestMatchDifference = 999;
                        string bestMatchPath = "";

                        //compare the facial parameters to each item in the TestSet-file
                        TestSetFile tsf = TestSetFile.readFromFile();
                        foreach (TestSet ts in tsf.testSets)
                        {
                            double difference = 0;
                            for (int i = 0; i < ts.Parameters.Length; i++)
                            {
                                difference += Math.Abs(ts.Parameters[i] - facialParamters[i]);
                            }
                            //the representation is currently compared by the average difference in values
                            difference /= facialParamters.Length;

                            if (difference < bestMatchDifference)
                            {
                                bestMatchDifference = difference;
                                bestMatchName = ts.Name;
                                bestMatchPath = ts.ImagePath;
                            }
                        }
                        if (tsf.testSets.Count < 1 || bestMatchPath == null)
                        {
                            //Test set is empty!
                            log("TestSet is leeg. Scan eerst een aantal gezichten in! ");
                        }
                        else 
                        {
                            resultPictureBox.Image = new Bitmap(bestMatchPath);
                            log("Best match is: " + bestMatchName + "  (gemiddeld verschil:" + bestMatchDifference + ")");
                        }
                    }
                    else
                    {
                        log("Testset-file bestaat niet of is niet gevonden.");
                    }
                }

                for (int i = 0; i < facialParamters.Length; i++)
                {
                    //uncomment if you want to print the found facial parameters in the feedbackTextBox
                    //log("param#" + (i + 1) + ": " + facialParamters[i]);
                }
            }
            else
            {
                log("Geen facial parameters beschikbaar.");
                log("Match berekenen is mislukt.");
            }
        }

        //Right-click on a picturebox will allow you to save the img
        private void saveImageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ToolStripMenuItem item = (ToolStripMenuItem)sender;
            ContextMenuStrip menuStrip = (ContextMenuStrip)item.Owner;

            saveImageWithFileDialog((PictureBox)menuStrip.SourceControl);
        }

        private string saveImageToTestSetDir(Image image, string name)
        {
            int n = 0;
            string testSetDir;

            //Standard file name, on a relative path, where all the scanned images will be saved to
            testSetDir = "TestSet Images";

            if (!System.IO.Directory.Exists(testSetDir))
            {
                System.IO.Directory.CreateDirectory(testSetDir);
            }

            //Vurnarable to race conditions!
            string dir = testSetDir;
            string fileName = name;
            string tempFileName = name + ".png";
            string path;

            //Check the first available file name:
            //example: if you want to save Ellen.png but one already exists it will try save it to Ellen1.png
            int i;
            for (i = 1; ; ++i)
            {
                path = System.IO.Path.Combine(testSetDir, tempFileName);
                if (!System.IO.File.Exists(System.IO.Path.Combine(testSetDir, tempFileName))){
                    break;
                }

                tempFileName = fileName + i + ".png" ;
            }

            image.Save(path, System.Drawing.Imaging.ImageFormat.Png);

            return path;            //First available index of the given name
        }

        //Right-click on a picturebox will allow you to clear the img
        private void clearImageToolStripMenuItem_Click(object sender, EventArgs e)
        {
            ToolStripMenuItem item = (ToolStripMenuItem)sender;
            ContextMenuStrip menuStrip = (ContextMenuStrip)item.Owner;
            ((PictureBox)menuStrip.SourceControl).Image = null;
        }

        //Right-click on a picturebox will allow you to open the img in a new window
        private void openInNewWindowToolStripMenuItem_Click(object sender, EventArgs e)
        {
            PictureForm pForm;

            //it can be opened by both a double-click and a right-click, as they have different senders we need to check where to retrieve te image from 
            if (sender is PictureBox) 
            {
                pForm = new PictureForm(((PictureBox) sender).Image);
            } 
            else
            {
                ToolStripMenuItem item = (ToolStripMenuItem)sender;
                ContextMenuStrip menuStrip = (ContextMenuStrip)item.Owner;

                pForm = new PictureForm(((PictureBox)menuStrip.SourceControl).Image);
            }

            pForm.Show();
        }

        private void pictureContextMenu_Opening(object sender, CancelEventArgs e)
        {

            ContextMenuStrip menuStrip = (ContextMenuStrip)sender;

            if (((PictureBox)menuStrip.SourceControl).Image == null)
            {
                pictureContextMenu.Enabled = false;
            }
            else
            {
                pictureContextMenu.Enabled = true;
            }
        }

        private void kiesAfbeeldingToolStripMenuItem_Click(object sender, EventArgs e)
        {
            openImageWithFileDialog(mainPictureBox);
        }

        //method for an open file dialog (with standard image extention)
        private void openImageWithFileDialog(PictureBox destination)
        {
            FileDialog fileDialog = new OpenFileDialog();
            fileDialog.Filter = "All Types|*.*;|bmp(*.bmp, *.BMP)|*.BMP;| jpg(*.jpg, *.jpeg, *.Jpg, *.JPG)|*.jpg;|png(*.png, *.PNG)|*.png;";
            fileDialog.AddExtension = true;
            if (fileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                Image img = new Bitmap(fileDialog.FileName);
                destination.Image = img;
                fileDialog.RestoreDirectory = true;
            }
        }

        //method for a save file dialog (with standard image extention)
        private void saveImageWithFileDialog(PictureBox origin)
        {
            FileDialog fileDialog = new SaveFileDialog();
            fileDialog.Filter = "bmp(*.bmp, *.BMP)|*.BMP;| jpg(*.jpg, *.jpeg, *.Jpg, *.JPG)|*.jpg;|png(*.png, *.PNG)|*.png;|All Types|*.*";
            fileDialog.AddExtension = true;
            if (fileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                switch (System.IO.Path.GetExtension(fileDialog.FileName).ToUpper())
                {
                    case ".BMP":
                        origin.Image.Save(fileDialog.FileName, System.Drawing.Imaging.ImageFormat.Bmp);
                        break;
                    case ".JPG":
                        origin.Image.Save(fileDialog.FileName, System.Drawing.Imaging.ImageFormat.Jpeg);
                        break;
                    case ".PNG":
                        origin.Image.Save(fileDialog.FileName, System.Drawing.Imaging.ImageFormat.Png);
                        break;
                    default:
                        break;
                }
            }
        }

        private void afbeeldingOpslaanToolStripMenuItem_Click(object sender, EventArgs e)
        {
            saveImageWithFileDialog(mainPictureBox);
        }

        private void afbeeldingenOpslaanToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //TODO:
            //Set directory + save all files to given directory
        }

        private void menuToolStripMenuItem_DropDownOpening(object sender, EventArgs e)
        {
            if (mainPictureBox.Image == null)
            {
                afbeeldingenOpslaanToolStripMenuItem.Enabled = false;
                afbeeldingOpslaanToolStripMenuItem.Enabled = false;
            }
            else
            {
                afbeeldingenOpslaanToolStripMenuItem.Enabled = true;
                afbeeldingOpslaanToolStripMenuItem.Enabled = true;
            }
        }

        private void helpToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Open README.txt
            System.Diagnostics.Process.Start("notepad.exe", "README.txt");
        }

        private void dLLOptiesToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Open Options window
            if (oForm == null || oForm.IsDisposed)
            {
                oForm = new OptionsForm();
            }
            oForm.Show();
        }

        private void scanRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (scanRadioButton.Checked == false)
            {
                nameLabel.Visible = false;
                nameTextBox.Visible = false;
            }
            else
            {
                nameLabel.Visible = true;
                nameTextBox.Visible = true;
            }
        }

        private void testsetBeherenToolStripMenuItem_Click(object sender, EventArgs e)
        {
            //Open TestSetManagerForm
            if (tmForm == null || tmForm.IsDisposed)
            {
                tmForm = new TestsetManagerForm();
            }
            tmForm.Show();
            //feedbackTextBox.Text = "" + ((ConfigurationManager.AppSettings["testSetPath"] != null) ? ConfigurationManager.AppSettings["testSetPath"].ToString() : "");
        }

        private void log(String logMessage)
        {
            feedbackTextBox.AppendText(logMessage + "\n");
        }

        private void sequenceRadioButton_CheckedChanged(object sender, EventArgs e)
        {
            if (sequenceRadioButton.Checked == false)
            {
                sequenceLabel.Visible = false;
                sequenceTextBox.Visible = false;
            }
            else
            {
                sequenceLabel.Visible = true;
                sequenceTextBox.Visible = true;
            }
        }

        //double-click on the textBox will open a file dialog
        private void sequenceTextBox_DoubleClick(object sender, EventArgs e)
        {
            
            //Open FileDialog
            FileDialog fileDialog = new OpenFileDialog();
            fileDialog.Filter = "XML-File|*.xml";
            fileDialog.AddExtension = true;
            if (fileDialog.ShowDialog() == System.Windows.Forms.DialogResult.OK)
            {
                sequenceTextBox.Text = fileDialog.FileName;
                fileDialog.RestoreDirectory = true;
            }

        }

    }
}
