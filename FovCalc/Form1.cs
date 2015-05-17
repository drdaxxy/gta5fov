using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Windows.Forms;
using System.Xml;


namespace FovCalc
{
    public partial class Form1 : Form
    {

        public string[] Resolutions = { "640x480", "800x600", "1024x768", "1920x1200", "1280x720", "1920x1080", "2560x1080", "2560x1440", "3840×2160" };

        // GTA V configuration parsed 
        public string gtavWidth = "";
        public string gtavHeight = "";

        // Selected width and height
        public int sWidth;
        public int sHeight;

        public double vFovRad;
        public double hFovRad;
        double vFov;

        public Form1()
        {
            InitializeComponent();

            string gtavSettingsFile = System.Environment.GetFolderPath(Environment.SpecialFolder.MyDocuments)+"\\Rockstar Games\\GTA V\\settings.xml";
            XmlReader xmlReader = XmlReader.Create(gtavSettingsFile);
            while (xmlReader.Read())
            {

                if ((xmlReader.NodeType == XmlNodeType.Element) && (xmlReader.Name == "ScreenWidth"))
                {
                    if (xmlReader.HasAttributes)
                        gtavWidth = xmlReader.GetAttribute("value");
                }
                if ((xmlReader.NodeType == XmlNodeType.Element) && (xmlReader.Name == "ScreenHeight"))
                {
                    if (xmlReader.HasAttributes)
                        gtavHeight = xmlReader.GetAttribute("value");
                }
            }

            resolutionList.Items.AddRange(Resolutions);
            resolutionList.SelectedIndex = 1;

            if (Array.IndexOf(Resolutions, gtavWidth + "x" + gtavHeight) > -1)
            {
                resolutionList.SelectedIndex = Array.IndexOf(Resolutions, gtavWidth + "x" + gtavHeight);
                sWidth = Convert.ToInt32(gtavWidth);
                sHeight = Convert.ToInt32(gtavHeight);

            }
        }

        private void calcFov()
        {
            //https://en.wikipedia.org/wiki/Field_of_view_in_video_games#Field_of_view_calculations
            double hFovRad = ((double.Parse(desiredHFovInput.Text) / (double) 180) * Math.PI);
            double vFovRad = 2 * Math.Atan(Math.Tan(hFovRad / (double) 2) * ((double) sHeight / (double) sWidth));
            double vFov = Math.Round((vFovRad * 180) / Math.PI);
            calculatedVFovInput.Text = vFov.ToString();

        }

        // Re calculate on horizontal fov changed
        private void desiredHFovInput_TextChanged(object sender, EventArgs e)
        {
            calcFov();
        }

        // Re-apply resolution if a new one is selected
        private void resolutionList_SelectedIndexChanged(object sender, EventArgs e)
        {
            string[] sArr = resolutionList.SelectedItem.ToString().Split('x');
            sWidth  = Convert.ToInt32(sArr[0]);
            sHeight = Convert.ToInt32(sArr[1]);
            calcFov();

        }

        // Re-apply resolution if modified manually
        private void resolutionList_TextUpdate(object sender, EventArgs e)
        {
            string[] sArr = resolutionList.Text.ToString().Split('x');
            sWidth = Convert.ToInt32(sArr[0]);
            sHeight = Convert.ToInt32(sArr[1]);
            calcFov();
        }
    }
}
