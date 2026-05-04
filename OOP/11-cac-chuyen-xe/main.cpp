#include "ChuyenXeNgoaiThanh.h"
#include "ChuyenXeNoiThanh.h"

int main()
{
    ChuyenXeNoiThanh noiThanh1, noiThanh2;
    ChuyenXeNgoaiThanh ngoaiThanh1, ngoaiThanh2;

    cout << "\n----NHAP XE NOI THANH----";
    cout << "----NHAP XE 1----\n";
    noiThanh1.nhapXeNoiThanh();
    cout << "\n----Nhap Xe 2----\n";
    noiThanh2.nhapXeNoiThanh();

    cout << "\n------THONG TIN XE NOI THANH------\n";
    cout << "\n----Thong tin xe 1----\n";
    noiThanh1.xuatXeNoiThanh();
    cout << "\n----Thong tin Xe 2----\n";
    noiThanh2.xuatXeNoiThanh();

    cout << "\n----NHAP XE NGOAI THANH----";
    cout << "\n----NHAP XE 1----\n";
    ngoaiThanh1.nhapXeNgoaiThanh();
    cout << "\n----Nhap Xe 2----\n";
    ngoaiThanh2.nhapXeNgoaiThanh();

    cout << "\n------THONG TIN XE NGOAI THANH------\n";
    cout << "----Thong tin xe 1----\n";
    ngoaiThanh1.xuatXeNgoaiThanh();
    cout << "\n----Thong tin Xe 2----\n";
    ngoaiThanh2.xuatXeNgoaiThanh();

    cout << "\n---Tong doanh thu: "
         << noiThanh1.getDoanhThu() + noiThanh2.getDoanhThu() + ngoaiThanh1.getDoanhThu() +
                ngoaiThanh2.getDoanhThu();
}