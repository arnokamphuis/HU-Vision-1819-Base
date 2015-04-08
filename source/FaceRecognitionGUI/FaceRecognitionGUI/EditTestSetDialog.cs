using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace FaceRecognitionGUI
{
    public partial class EditTestSetDialog : Form
    {
        private TestSetFile testSetFile;
        private int itemIndex;
        private double[] parameters;

        public EditTestSetDialog(TestSetFile tsf, int itemIndex)
        {
            InitializeComponent();

            testSetFile = tsf;
            this.itemIndex = itemIndex;
        }

        //when opening the window load the test set data into the textboxes
        private void EditTestSetDialog_Load(object sender, EventArgs e)
        {
            //Load the in TestsetManagerForm selected Item into the two TextBoxes
            textBox1.Text = testSetFile.testSets[itemIndex].Name;
            
            string output = String.Join(";", testSetFile.testSets[itemIndex].Parameters.Select(p => p.ToString()));//.ToArray());
            textBox2.Text = output;

            textBox3.Text = testSetFile.testSets[itemIndex].ImagePath;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double[] parameters = new double[16];
            String error = "";
            if (!validateParameters(textBox2.Text, out parameters, out error)){
                //Should never happen!
            }
            else
            {
                this.parameters = parameters;
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            //Cancel the made changes and dispose of this window.
        }

        public string getName()
        {
            return textBox1.Text;
        }

        public double[] getParameters()
        {
            return parameters;
        }

        private bool validateParameters(string parameterText, out double[] validParameters, out string errorMessage)
        {
            //check if all the parameters are valid by trying to split the 16 parameters with ';'
            try
            {
                validParameters = Array.ConvertAll(parameterText.Split(';'), double.Parse);
                if (validParameters.Length != 16)
                {
                    validParameters = testSetFile.testSets[itemIndex].Parameters;
                    errorMessage = "Er moeten 16 Parameters zijn.";

                    return false;
                }
                Console.WriteLine("Er zijn genoeg params ...");
            }
            catch (System.FormatException e)
            {
                errorMessage = "Parameters moeten allemaal doubles zijn, gesepereerd door puntcomma's.";
                validParameters = testSetFile.testSets[itemIndex].Parameters;

                return false;
            }

            errorMessage = "";
            return true;
        }

        private void textBox2_Validating(object sender, CancelEventArgs e)
        {
            //Validate the Parameters entered in textBox2
            string parametersText = textBox2.Text;
            double[] parameters = new double[16];
            string errorMessage;

            if (!validateParameters(parametersText, out parameters, out errorMessage))
            {
                e.Cancel = true;
                textBox2.Select(0, textBox2.Text.Length);
                //set a error note visible to the user
                this.errorProvider1.SetError(textBox2, errorMessage);
            }
            else
            {
                this.parameters = parameters;
            }
        }

        private void textBox2_Validated(object sender, EventArgs e)
        {
            //After validation of textBox2 is complete clear error message
            errorProvider1.SetError(textBox2, "");
        }
    }
}
