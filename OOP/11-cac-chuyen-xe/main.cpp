#include "ChuyenXeNgoaiThanh.h"
#include "ChuyenXeNoiThanh.h"

int main()
{
    ChuyenXeNoiThanh noiThanh1, noiThanh2;
    ChuyenXeNgoaiThanh ngoaiThanh1, ngoaiThanh2;

    cout << "\n----NHAP XE NOI THANH----";
    cout << "----NHAP XE 1----\n";
    noiThanh1.nhap();
    cout << "\n----Nhap Xe 2----\n";
    noiThanh2.nhap();

    cout << "\n------THONG TIN XE NOI THANH------\n";
    cout << "\n----Thong tin xe 1----\n";
    noiThanh1.xuat();
    cout << "\n----Thong tin Xe 2----\n";
    noiThanh2.xuat();

    cout << "\n----NHAP XE NGOAI THANH----";
    cout << "\n----NHAP XE 1----\n";
    ngoaiThanh1.nhap();
    cout << "\n----Nhap Xe 2----\n";
    ngoaiThanh2.nhap();

    cout << "\n------THONG TIN XE NGOAI THANH------\n";
    cout << "----Thong tin xe 1----\n";
    ngoaiThanh1.xuat();
    cout << "\n----Thong tin Xe 2----\n";
    ngoaiThanh2.xuat();

    cout << "\n---Tong doanh thu: "
         << noiThanh1.getDoanhThu() + noiThanh2.getDoanhThu() + ngoaiThanh1.getDoanhThu() +
                ngoaiThanh2.getDoanhThu();
}