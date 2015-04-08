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
    //window used to view the image in
    public partial class PictureForm : Form
    {
        public PictureForm(Image img)
        {
            InitializeComponent();
            pictureFormBox.Image = img;
        }

        private void PictureForm_Load(object sender, EventArgs e)
        {

        }
    }
}
