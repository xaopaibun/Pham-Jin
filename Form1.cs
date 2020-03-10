using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Bai4
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }
        int CanNangLyTuong = 0;
        int N = 0;
        
        private void btnTinh_Click(object sender, EventArgs e)
        {
            int T = int.Parse(txtChieuCao.Text); // Chuyển từ chuỗi sang số nguyên 
            if(radioNam.Checked == true) // nếu chọn gt nam thfi n = 4
            {
                N = 4;
            }
            else if(radioNu.Checked == true) 
            {
                N = 2;
            }
            int CanNang = int.Parse(txtCanNang.Text);
            CanNangLyTuong = T - 100 - (T - 150 / N); // đúng CT r mà nhỉ có biết j đau mà hỏi
            if(CanNangLyTuong > CanNang)
            {
                lblKQ.Text = "Bạn Có Cân Nặng Lý Tưởng Là " + CanNangLyTuong + "\nBạn Đang Thừa Cân !";
            }
            if(CanNangLyTuong == CanNang)
            {
                lblKQ.Text = "Bạn Có Cân Nặng Qúa Lí Tưởng Là " + CanNangLyTuong + "KG ";
            }
            else
            {
                lblKQ.Text = "Bạn Có Cân Nặng Lý Tưởng Là " + CanNangLyTuong + "\nBạn Đang Bị Thiếu Cân !";

            }
            
        }

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void btnXoa_Click(object sender, EventArgs e)
        {
            txtHoTen.Text = "";
            txtCanNang.Text = "";
            txtChieuCao.Text = "";
            groupBox1.Text = "";
        }

        private void btnThoat_Click(object sender, EventArgs e)
        {
            MessageBox.Show("Thoát Chương Trình ", "Bạn Muốn Thoát Không !", MessageBoxButtons.YesNo, MessageBoxIcon.Question);
            Close();
        }
    }
}
