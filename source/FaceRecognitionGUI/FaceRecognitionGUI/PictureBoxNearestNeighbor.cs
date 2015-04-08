using System;
using System.Collections.Generic;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;


namespace FaceRecognitionGUI {
    class PictureBoxNearestNeighbor : PictureBox {

        //use NearestNeighbor when increasing the size of the picture boxes
        //this way it is not blurred
        protected override void OnPaint(PaintEventArgs paintEventArgs) {
            paintEventArgs.Graphics.InterpolationMode = InterpolationMode.NearestNeighbor;
            base.OnPaint(paintEventArgs);
        }
    }
}
