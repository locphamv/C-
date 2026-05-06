
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;

struct NGAY {
    int Ngay, Thang, Nam;
};
struct SINHVIEN {
    string MASV;
    string HoTen;
    NGAY NgaySinh;
    char GioiTinh;
    float DiemToan, DiemLy, DiemHoa, DTB;
};
struct NODE{
    SINHVIEN key;
    NODE* pNext;
};
struct LIST{
    NODE*pHead, *pTail;
};

void NhapNgay(NGAY &);
void XuatNgay(NGAY );
void NhapSinhVien(SINHVIEN &);
void XuatSinhVien(SINHVIEN );
NODE* CreateNode(SINHVIEN );
void CreateEmptyList(LIST &);
void AddTail(LIST&, NODE* );
void XuatDS(LIST );
void NhapDS(LIST &, int n);
bool Xoa_TheoHoTen(LIST &, string);

int main() {
    LIST L;
    int n;
    string hoten;

    getline(cin, hoten);
    cin >> n ;

    NhapDS(L, n);

    Xoa_TheoHoTen(L, hoten);

    XuatDS(L);

    return 0;
}

void NhapNgay(NGAY &a){
    cin >> a.Ngay >> a.Thang >> a.Nam;
}
void XuatNgay(NGAY a){
    cout << a.Ngay << "/" << a.Thang << "/" << a.Nam;
}
void NhapSinhVien(SINHVIEN &a){
    cin >> ws;
    getline(cin, a.MASV);
    getline(cin, a.HoTen);
    NhapNgay(a.NgaySinh);
    cin >> a.GioiTinh;
    cin >> a.DiemToan >> a.DiemLy >> a.DiemHoa;
    a.DTB = (a.DiemToan + a.DiemLy + a.DiemHoa) / 3;
}
void XuatSinhVien(SINHVIEN a){
    cout << a.MASV;         cout << "\t";
    cout << a.HoTen;        cout << "\t";
    XuatNgay(a.NgaySinh);   cout << "\t";
    cout << a.GioiTinh;     cout << "\t";
    cout << a.DiemToan;     cout << "\t";
    cout << a.DiemLy;       cout << "\t";
    cout << a.DiemHoa;      cout << "\t";
    cout << setprecision(3);
    cout << a.DTB;
}



NODE* CreateNode(SINHVIEN x)
{
    NODE*p=new NODE;
    p->key.MASV=x.MASV;
    p->key.HoTen=x.HoTen;
    p->key.NgaySinh=x.NgaySinh;
    p->key.GioiTinh=x.GioiTinh;
    p->key.DiemToan=x.DiemToan;
    p->key.DiemLy=x.DiemLy;
    p->key.DiemHoa=x.DiemHoa;
    p->key.DTB=x.DTB;
    p->pNext=NULL;
    return p;
}

void CreateEmptyList(LIST &L)
{
    L.pHead=NULL;
    L.pTail=NULL;
}

void AddTail(LIST& l, NODE* p)
{
    if(l.pHead==NULL)
    {
        l.pHead=p;
        l.pTail=p;
    }
    else
    {
        l.pTail->pNext=p;
        l.pTail=p;
    }
}

void XuatDS(LIST L)
{
    NODE*p=L.pHead;
    if(p==NULL)
    {
        cout<<"Empty List.";
    }
    while(p)
    {
        XuatSinhVien(p->key);
        cout<<"\n";
        p=p->pNext;
    }
}
void NhapDS(LIST &L, int n)
{
    CreateEmptyList(L);
    SINHVIEN x;
    for(int i=0; i<n; i++)
    {
        NhapSinhVien(x);
        AddTail(L,CreateNode(x));
    }
}

bool Xoa_TheoHoTen(LIST &L, string ten)
{
    NODE*p=L.pHead;
    NODE* tmp=NULL;
    while(p != NULL)
    {
        if(L.pHead->key.HoTen==ten && p==L.pTail) 
        {
            delete L.pHead;        
            L.pHead=L.pTail=p=NULL;
            return false;
        }

        if(L.pHead->key.HoTen!=ten && p==L.pTail) 
        {
            return true;
        }

        if(L.pHead->key.HoTen==ten)  
        {
             tmp=L.pHead;
            L.pHead=p=p->pNext;
            delete tmp;
            tmp=NULL;
            continue;
        }

        if( p->pNext==L.pTail && p->pNext->key.HoTen==ten) 
        {
            tmp=L.pTail;
            L.pTail=p;
            p->pNext=NULL;
            delete tmp;
            break;
        }

        if(p->pNext->key.HoTen==ten && p->pNext->pNext!=NULL)
        {
            NODE*tmp=p->pNext;
            p->pNext=tmp->pNext;
            delete tmp;
            tmp=NULL;
            continue;
        }
       
        p=p->pNext;
    }
    return true;
}