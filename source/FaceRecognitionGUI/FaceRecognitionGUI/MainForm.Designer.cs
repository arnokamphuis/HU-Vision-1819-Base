namespace FaceRecognitionGUI
{
    partial class MainForm
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
            this.components = new System.ComponentModel.Container();
            this.mainPictureBox = new System.Windows.Forms.PictureBox();
            this.pictureContextMenu = new System.Windows.Forms.ContextMenuStrip(this.components);
            this.openInNewWindowToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.saveImageToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.clearImageToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.toolStrip = new System.Windows.Forms.MenuStrip();
            this.menuToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.kiesAfbeeldingToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.afbeeldingOpslaanToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.afbeeldingenOpslaanToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.optiesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.dLLOptiesToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.testsetBeherenToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.helpToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.pictureBox2 = new System.Windows.Forms.PictureBox();
            this.feedbackTextBox = new System.Windows.Forms.TextBox();
            this.pictureBox4 = new System.Windows.Forms.PictureBox();
            this.pictureBox3 = new System.Windows.Forms.PictureBox();
            this.pictureBox5 = new System.Windows.Forms.PictureBox();
            this.statusStrip = new System.Windows.Forms.StatusStrip();
            this.toolStripStatusLabel1 = new System.Windows.Forms.ToolStripStatusLabel();
            this.toolStripStatusLabel2 = new System.Windows.Forms.ToolStripStatusLabel();
            this.feedbackLabel = new System.Windows.Forms.Label();
            this.backgroundWorker = new System.ComponentModel.BackgroundWorker();
            this.ExecutionLabel = new System.Windows.Forms.Label();
            this.ExecuteButton = new System.Windows.Forms.Button();
            this.scanRadioButton = new System.Windows.Forms.RadioButton();
            this.recognizeRadioButton = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.sequenceTextBox = new System.Windows.Forms.TextBox();
            this.sequenceLabel = new System.Windows.Forms.Label();
            this.sequenceRadioButton = new System.Windows.Forms.RadioButton();
            this.nameLabel = new System.Windows.Forms.Label();
            this.nameTextBox = new System.Windows.Forms.TextBox();
            this.resultPictureBox = new System.Windows.Forms.PictureBox();
            ((System.ComponentModel.ISupportInitialize)(this.mainPictureBox)).BeginInit();
            this.pictureContextMenu.SuspendLayout();
            this.toolStrip.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).BeginInit();
            this.statusStrip.SuspendLayout();
            this.groupBox1.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.resultPictureBox)).BeginInit();
            this.SuspendLayout();
            // 
            // mainPictureBox
            // 
            this.mainPictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.mainPictureBox.ContextMenuStrip = this.pictureContextMenu;
            this.mainPictureBox.Location = new System.Drawing.Point(12, 36);
            this.mainPictureBox.Name = "mainPictureBox";
            this.mainPictureBox.Size = new System.Drawing.Size(286, 260);
            this.mainPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.mainPictureBox.TabIndex = 1;
            this.mainPictureBox.TabStop = false;
            this.mainPictureBox.DoubleClick += new System.EventHandler(this.mainPictureBox_DoubleClick);
            // 
            // pictureContextMenu
            // 
            this.pictureContextMenu.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.openInNewWindowToolStripMenuItem,
            this.saveImageToolStripMenuItem,
            this.clearImageToolStripMenuItem});
            this.pictureContextMenu.Name = "contextMenuStrip1";
            this.pictureContextMenu.Size = new System.Drawing.Size(189, 70);
            this.pictureContextMenu.Opening += new System.ComponentModel.CancelEventHandler(this.pictureContextMenu_Opening);
            // 
            // openInNewWindowToolStripMenuItem
            // 
            this.openInNewWindowToolStripMenuItem.Name = "openInNewWindowToolStripMenuItem";
            this.openInNewWindowToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.openInNewWindowToolStripMenuItem.Text = "Open in new Window";
            this.openInNewWindowToolStripMenuItem.Click += new System.EventHandler(this.openInNewWindowToolStripMenuItem_Click);
            // 
            // saveImageToolStripMenuItem
            // 
            this.saveImageToolStripMenuItem.Name = "saveImageToolStripMenuItem";
            this.saveImageToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.saveImageToolStripMenuItem.Text = "Save Image";
            this.saveImageToolStripMenuItem.Click += new System.EventHandler(this.saveImageToolStripMenuItem_Click);
            // 
            // clearImageToolStripMenuItem
            // 
            this.clearImageToolStripMenuItem.Name = "clearImageToolStripMenuItem";
            this.clearImageToolStripMenuItem.Size = new System.Drawing.Size(188, 22);
            this.clearImageToolStripMenuItem.Text = "Clear Image";
            this.clearImageToolStripMenuItem.Click += new System.EventHandler(this.clearImageToolStripMenuItem_Click);
            // 
            // toolStrip
            // 
            this.toolStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.menuToolStripMenuItem,
            this.optiesToolStripMenuItem});
            this.toolStrip.Location = new System.Drawing.Point(0, 0);
            this.toolStrip.Name = "toolStrip";
            this.toolStrip.Size = new System.Drawing.Size(879, 24);
            this.toolStrip.TabIndex = 4;
            this.toolStrip.Text = "menuStrip2";
            // 
            // menuToolStripMenuItem
            // 
            this.menuToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.kiesAfbeeldingToolStripMenuItem,
            this.afbeeldingOpslaanToolStripMenuItem,
            this.afbeeldingenOpslaanToolStripMenuItem});
            this.menuToolStripMenuItem.Name = "menuToolStripMenuItem";
            this.menuToolStripMenuItem.Size = new System.Drawing.Size(50, 20);
            this.menuToolStripMenuItem.Text = "Menu";
            this.menuToolStripMenuItem.DropDownOpening += new System.EventHandler(this.menuToolStripMenuItem_DropDownOpening);
            // 
            // kiesAfbeeldingToolStripMenuItem
            // 
            this.kiesAfbeeldingToolStripMenuItem.Name = "kiesAfbeeldingToolStripMenuItem";
            this.kiesAfbeeldingToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.kiesAfbeeldingToolStripMenuItem.Text = "Kies Afbeelding";
            this.kiesAfbeeldingToolStripMenuItem.Click += new System.EventHandler(this.kiesAfbeeldingToolStripMenuItem_Click);
            // 
            // afbeeldingOpslaanToolStripMenuItem
            // 
            this.afbeeldingOpslaanToolStripMenuItem.Name = "afbeeldingOpslaanToolStripMenuItem";
            this.afbeeldingOpslaanToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.afbeeldingOpslaanToolStripMenuItem.Text = "Afbeelding Opslaan";
            this.afbeeldingOpslaanToolStripMenuItem.Click += new System.EventHandler(this.afbeeldingOpslaanToolStripMenuItem_Click);
            // 
            // afbeeldingenOpslaanToolStripMenuItem
            // 
            this.afbeeldingenOpslaanToolStripMenuItem.Enabled = false;
            this.afbeeldingenOpslaanToolStripMenuItem.Name = "afbeeldingenOpslaanToolStripMenuItem";
            this.afbeeldingenOpslaanToolStripMenuItem.Size = new System.Drawing.Size(191, 22);
            this.afbeeldingenOpslaanToolStripMenuItem.Text = "Afbeeldingen Opslaan";
            this.afbeeldingenOpslaanToolStripMenuItem.Click += new System.EventHandler(this.afbeeldingenOpslaanToolStripMenuItem_Click);
            // 
            // optiesToolStripMenuItem
            // 
            this.optiesToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.dLLOptiesToolStripMenuItem,
            this.testsetBeherenToolStripMenuItem,
            this.helpToolStripMenuItem});
            this.optiesToolStripMenuItem.Name = "optiesToolStripMenuItem";
            this.optiesToolStripMenuItem.Size = new System.Drawing.Size(53, 20);
            this.optiesToolStripMenuItem.Text = "Opties";
            // 
            // dLLOptiesToolStripMenuItem
            // 
            this.dLLOptiesToolStripMenuItem.Name = "dLLOptiesToolStripMenuItem";
            this.dLLOptiesToolStripMenuItem.Size = new System.Drawing.Size(162, 22);
            this.dLLOptiesToolStripMenuItem.Text = "Algoritme opties";
            this.dLLOptiesToolStripMenuItem.Click += new System.EventHandler(this.dLLOptiesToolStripMenuItem_Click);
            // 
            // testsetBeherenToolStripMenuItem
            // 
            this.testsetBeherenToolStripMenuItem.Name = "testsetBeherenToolStripMenuItem";
            this.testsetBeherenToolStripMenuItem.Size = new System.Drawing.Size(162, 22);
            this.testsetBeherenToolStripMenuItem.Text = "Testset beheren";
            this.testsetBeherenToolStripMenuItem.Click += new System.EventHandler(this.testsetBeherenToolStripMenuItem_Click);
            // 
            // helpToolStripMenuItem
            // 
            this.helpToolStripMenuItem.Name = "helpToolStripMenuItem";
            this.helpToolStripMenuItem.Size = new System.Drawing.Size(162, 22);
            this.helpToolStripMenuItem.Text = "Help";
            this.helpToolStripMenuItem.Click += new System.EventHandler(this.helpToolStripMenuItem_Click);
            // 
            // pictureBox2
            // 
            this.pictureBox2.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox2.ContextMenuStrip = this.pictureContextMenu;
            this.pictureBox2.Location = new System.Drawing.Point(304, 36);
            this.pictureBox2.Name = "pictureBox2";
            this.pictureBox2.Size = new System.Drawing.Size(131, 127);
            this.pictureBox2.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox2.TabIndex = 7;
            this.pictureBox2.TabStop = false;
            this.pictureBox2.DoubleClick += new System.EventHandler(this.openInNewWindowToolStripMenuItem_Click);
            // 
            // feedbackTextBox
            // 
            this.feedbackTextBox.Location = new System.Drawing.Point(12, 319);
            this.feedbackTextBox.Multiline = true;
            this.feedbackTextBox.Name = "feedbackTextBox";
            this.feedbackTextBox.ReadOnly = true;
            this.feedbackTextBox.Size = new System.Drawing.Size(668, 168);
            this.feedbackTextBox.TabIndex = 11;
            this.feedbackTextBox.Text = "GUI opgestart";
            // 
            // pictureBox4
            // 
            this.pictureBox4.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox4.ContextMenuStrip = this.pictureContextMenu;
            this.pictureBox4.Location = new System.Drawing.Point(304, 169);
            this.pictureBox4.Name = "pictureBox4";
            this.pictureBox4.Size = new System.Drawing.Size(131, 127);
            this.pictureBox4.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox4.TabIndex = 12;
            this.pictureBox4.TabStop = false;
            this.pictureBox4.DoubleClick += new System.EventHandler(this.openInNewWindowToolStripMenuItem_Click);
            // 
            // pictureBox3
            // 
            this.pictureBox3.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox3.ContextMenuStrip = this.pictureContextMenu;
            this.pictureBox3.Location = new System.Drawing.Point(441, 36);
            this.pictureBox3.Name = "pictureBox3";
            this.pictureBox3.Size = new System.Drawing.Size(131, 127);
            this.pictureBox3.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox3.TabIndex = 13;
            this.pictureBox3.TabStop = false;
            this.pictureBox3.DoubleClick += new System.EventHandler(this.openInNewWindowToolStripMenuItem_Click);
            // 
            // pictureBox5
            // 
            this.pictureBox5.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pictureBox5.ContextMenuStrip = this.pictureContextMenu;
            this.pictureBox5.Location = new System.Drawing.Point(441, 169);
            this.pictureBox5.Name = "pictureBox5";
            this.pictureBox5.Size = new System.Drawing.Size(131, 127);
            this.pictureBox5.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.pictureBox5.TabIndex = 14;
            this.pictureBox5.TabStop = false;
            this.pictureBox5.DoubleClick += new System.EventHandler(this.openInNewWindowToolStripMenuItem_Click);
            // 
            // statusStrip
            // 
            this.statusStrip.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.toolStripStatusLabel1,
            this.toolStripStatusLabel2});
            this.statusStrip.Location = new System.Drawing.Point(0, 490);
            this.statusStrip.Name = "statusStrip";
            this.statusStrip.Size = new System.Drawing.Size(879, 22);
            this.statusStrip.SizingGrip = false;
            this.statusStrip.TabIndex = 15;
            this.statusStrip.Text = "statusStrip1";
            // 
            // toolStripStatusLabel1
            // 
            this.toolStripStatusLabel1.Name = "toolStripStatusLabel1";
            this.toolStripStatusLabel1.Size = new System.Drawing.Size(123, 17);
            this.toolStripStatusLabel1.Text = "Huidige vooruitgang: ";
            // 
            // toolStripStatusLabel2
            // 
            this.toolStripStatusLabel2.Name = "toolStripStatusLabel2";
            this.toolStripStatusLabel2.Size = new System.Drawing.Size(12, 17);
            this.toolStripStatusLabel2.Text = "-";
            // 
            // feedbackLabel
            // 
            this.feedbackLabel.AutoSize = true;
            this.feedbackLabel.Location = new System.Drawing.Point(12, 303);
            this.feedbackLabel.Name = "feedbackLabel";
            this.feedbackLabel.Size = new System.Drawing.Size(61, 13);
            this.feedbackLabel.TabIndex = 16;
            this.feedbackLabel.Text = "Feedback: ";
            // 
            // backgroundWorker
            // 
            this.backgroundWorker.DoWork += new System.ComponentModel.DoWorkEventHandler(this.backgroundWorker_DoWork);
            this.backgroundWorker.RunWorkerCompleted += new System.ComponentModel.RunWorkerCompletedEventHandler(this.backgroundWorker_RunWorkerCompleted);
            // 
            // ExecutionLabel
            // 
            this.ExecutionLabel.AutoSize = true;
            this.ExecutionLabel.Location = new System.Drawing.Point(6, 16);
            this.ExecutionLabel.Name = "ExecutionLabel";
            this.ExecutionLabel.Size = new System.Drawing.Size(70, 13);
            this.ExecutionLabel.TabIndex = 8;
            this.ExecutionLabel.Text = "Uitvoerwijze: ";
            // 
            // ExecuteButton
            // 
            this.ExecuteButton.Location = new System.Drawing.Point(686, 460);
            this.ExecuteButton.Name = "ExecuteButton";
            this.ExecuteButton.Size = new System.Drawing.Size(75, 27);
            this.ExecuteButton.TabIndex = 7;
            this.ExecuteButton.Text = "Uitvoeren";
            this.ExecuteButton.UseVisualStyleBackColor = true;
            this.ExecuteButton.Click += new System.EventHandler(this.executeButton_Click);
            // 
            // scanRadioButton
            // 
            this.scanRadioButton.AutoSize = true;
            this.scanRadioButton.Location = new System.Drawing.Point(9, 52);
            this.scanRadioButton.Name = "scanRadioButton";
            this.scanRadioButton.Size = new System.Drawing.Size(75, 17);
            this.scanRadioButton.TabIndex = 9;
            this.scanRadioButton.TabStop = true;
            this.scanRadioButton.Text = "Inscannen";
            this.scanRadioButton.UseVisualStyleBackColor = true;
            this.scanRadioButton.CheckedChanged += new System.EventHandler(this.scanRadioButton_CheckedChanged);
            // 
            // recognizeRadioButton
            // 
            this.recognizeRadioButton.AutoSize = true;
            this.recognizeRadioButton.Location = new System.Drawing.Point(9, 32);
            this.recognizeRadioButton.Name = "recognizeRadioButton";
            this.recognizeRadioButton.Size = new System.Drawing.Size(78, 17);
            this.recognizeRadioButton.TabIndex = 10;
            this.recognizeRadioButton.TabStop = true;
            this.recognizeRadioButton.Text = "Herkennen";
            this.recognizeRadioButton.UseVisualStyleBackColor = true;
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.sequenceTextBox);
            this.groupBox1.Controls.Add(this.sequenceLabel);
            this.groupBox1.Controls.Add(this.sequenceRadioButton);
            this.groupBox1.Controls.Add(this.nameLabel);
            this.groupBox1.Controls.Add(this.nameTextBox);
            this.groupBox1.Controls.Add(this.ExecutionLabel);
            this.groupBox1.Controls.Add(this.recognizeRadioButton);
            this.groupBox1.Controls.Add(this.scanRadioButton);
            this.groupBox1.Location = new System.Drawing.Point(687, 319);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(177, 135);
            this.groupBox1.TabIndex = 18;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Opties";
            // 
            // sequenceTextBox
            // 
            this.sequenceTextBox.Location = new System.Drawing.Point(68, 108);
            this.sequenceTextBox.Name = "sequenceTextBox";
            this.sequenceTextBox.Size = new System.Drawing.Size(100, 20);
            this.sequenceTextBox.TabIndex = 15;
            this.sequenceTextBox.Visible = false;
            this.sequenceTextBox.DoubleClick += new System.EventHandler(this.sequenceTextBox_DoubleClick);
            // 
            // sequenceLabel
            // 
            this.sequenceLabel.AutoSize = true;
            this.sequenceLabel.Location = new System.Drawing.Point(70, 91);
            this.sequenceLabel.Name = "sequenceLabel";
            this.sequenceLabel.Size = new System.Drawing.Size(41, 13);
            this.sequenceLabel.TabIndex = 14;
            this.sequenceLabel.Text = "xml-file:";
            this.sequenceLabel.Visible = false;
            // 
            // sequenceRadioButton
            // 
            this.sequenceRadioButton.AutoSize = true;
            this.sequenceRadioButton.Location = new System.Drawing.Point(9, 72);
            this.sequenceRadioButton.Name = "sequenceRadioButton";
            this.sequenceRadioButton.Size = new System.Drawing.Size(127, 17);
            this.sequenceRadioButton.TabIndex = 13;
            this.sequenceRadioButton.TabStop = true;
            this.sequenceRadioButton.Text = "Sequentie herkennen";
            this.sequenceRadioButton.UseVisualStyleBackColor = true;
            this.sequenceRadioButton.CheckedChanged += new System.EventHandler(this.sequenceRadioButton_CheckedChanged);
            // 
            // nameLabel
            // 
            this.nameLabel.AutoSize = true;
            this.nameLabel.Location = new System.Drawing.Point(69, 89);
            this.nameLabel.Name = "nameLabel";
            this.nameLabel.Size = new System.Drawing.Size(36, 13);
            this.nameLabel.TabIndex = 12;
            this.nameLabel.Text = "naam:";
            this.nameLabel.Visible = false;
            // 
            // nameTextBox
            // 
            this.nameTextBox.Location = new System.Drawing.Point(69, 108);
            this.nameTextBox.Name = "nameTextBox";
            this.nameTextBox.Size = new System.Drawing.Size(100, 20);
            this.nameTextBox.TabIndex = 11;
            this.nameTextBox.Visible = false;
            // 
            // resultPictureBox
            // 
            this.resultPictureBox.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.resultPictureBox.ContextMenuStrip = this.pictureContextMenu;
            this.resultPictureBox.Location = new System.Drawing.Point(579, 36);
            this.resultPictureBox.Name = "resultPictureBox";
            this.resultPictureBox.Size = new System.Drawing.Size(286, 260);
            this.resultPictureBox.SizeMode = System.Windows.Forms.PictureBoxSizeMode.Zoom;
            this.resultPictureBox.TabIndex = 19;
            this.resultPictureBox.TabStop = false;
            this.resultPictureBox.DoubleClick += new System.EventHandler(this.openInNewWindowToolStripMenuItem_Click);
            // 
            // MainForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(96F, 96F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Dpi;
            this.ClientSize = new System.Drawing.Size(879, 512);
            this.Controls.Add(this.resultPictureBox);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.ExecuteButton);
            this.Controls.Add(this.feedbackLabel);
            this.Controls.Add(this.statusStrip);
            this.Controls.Add(this.pictureBox5);
            this.Controls.Add(this.pictureBox3);
            this.Controls.Add(this.pictureBox4);
            this.Controls.Add(this.feedbackTextBox);
            this.Controls.Add(this.pictureBox2);
            this.Controls.Add(this.mainPictureBox);
            this.Controls.Add(this.toolStrip);
            this.Cursor = System.Windows.Forms.Cursors.Default;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.MaximumSize = new System.Drawing.Size(895, 550);
            this.MinimumSize = new System.Drawing.Size(895, 550);
            this.Name = "MainForm";
            this.ShowIcon = false;
            this.Text = "Face Recognition";
            ((System.ComponentModel.ISupportInitialize)(this.mainPictureBox)).EndInit();
            this.pictureContextMenu.ResumeLayout(false);
            this.toolStrip.ResumeLayout(false);
            this.toolStrip.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox2)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox4)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox3)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox5)).EndInit();
            this.statusStrip.ResumeLayout(false);
            this.statusStrip.PerformLayout();
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.resultPictureBox)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox mainPictureBox;
        private System.Windows.Forms.MenuStrip toolStrip;
        private System.Windows.Forms.ToolStripMenuItem menuToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem kiesAfbeeldingToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem afbeeldingOpslaanToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem afbeeldingenOpslaanToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem optiesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem dLLOptiesToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem helpToolStripMenuItem;
        private System.Windows.Forms.PictureBox pictureBox2;
        private System.Windows.Forms.PictureBox pictureBox3;
        private System.Windows.Forms.PictureBox pictureBox4;
        private System.Windows.Forms.PictureBox pictureBox5;
        private System.Windows.Forms.TextBox feedbackTextBox;
        private System.Windows.Forms.StatusStrip statusStrip;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel1;
        private System.Windows.Forms.Label feedbackLabel;
        private System.ComponentModel.BackgroundWorker backgroundWorker;
        private System.Windows.Forms.ContextMenuStrip pictureContextMenu;
        private System.Windows.Forms.ToolStripMenuItem saveImageToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem clearImageToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem openInNewWindowToolStripMenuItem;
        private System.Windows.Forms.ToolStripStatusLabel toolStripStatusLabel2;
        private System.Windows.Forms.Label ExecutionLabel;
        private System.Windows.Forms.Button ExecuteButton;
        private System.Windows.Forms.RadioButton scanRadioButton;
        private System.Windows.Forms.RadioButton recognizeRadioButton;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.Label nameLabel;
        private System.Windows.Forms.TextBox nameTextBox;
        private System.Windows.Forms.ToolStripMenuItem testsetBeherenToolStripMenuItem;
        private System.Windows.Forms.TextBox sequenceTextBox;
        private System.Windows.Forms.Label sequenceLabel;
        private System.Windows.Forms.RadioButton sequenceRadioButton;
        private System.Windows.Forms.PictureBox resultPictureBox;
    }
}

