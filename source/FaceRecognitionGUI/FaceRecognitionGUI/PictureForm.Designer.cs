namespace FaceRecognitionGUI
{
    partial class PictureForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.pictureFormBox = new PictureBoxNearestNeighbor();
            ((System.ComponentModel.ISupportInitialize)(this.pictureFormBox)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureFormBox
            // 
            this.pictureFormBox.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureFormBox.Location = new System.Drawing.Point(0, 0);
            this.pictureFormBox.Name = "pictureFormBox";
            this.pictureFormBox.Size = new System.Drawing.Size(612, 503);
            this.pictureFormBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureFormBox.TabIndex = 0;
            this.pictureFormBox.TabStop = false;
            // 
            // PictureForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(612, 503);
            this.Controls.Add(this.pictureFormBox);
            this.Name = "PictureForm";
            this.Text = "Afbeelding";
            this.Load += new System.EventHandler(this.PictureForm_Load);
            ((System.ComponentModel.ISupportInitialize)(this.pictureFormBox)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private PictureBoxNearestNeighbor pictureFormBox;
    }
}