#include <iostream>

using namespace std;

struct ogrenci{
    int ogrenci_no;
    struct ogrenci* next_ogr;
};

class Ogrenci_Listesi{
private:
    ogrenci* head;
    ogrenci* tail;
public:
    Ogrenci_Listesi(){
        head = nullptr;
        tail = nullptr;
    }

    void ogrenci_ekle(int _ogrNo){
        ogrenci* tmp = new ogrenci;
        tmp->ogrenci_no = _ogrNo;
        tmp->next_ogr = nullptr;
        if(head == nullptr){
            head = tmp;
            tail = tmp;
        }else{
            tail->next_ogr = tmp;
            tail = tmp;
        }
    }

    void ogrenci_sil(int _ogrNo){
        ogrenci* current = head;
        ogrenci* tmp = new ogrenci;
        while(current->next_ogr->ogrenci_no != _ogrNo){
            current = current->next_ogr;
        }
        tmp->next_ogr = current->next_ogr->next_ogr;
        current->next_ogr = tmp->next_ogr;
    }

    void ogrenci_listele(){
        ogrenci* current = head;
        int sayac = 1;
        while(current != nullptr){
            cout << sayac << ".Ogrenci No :" << current->ogrenci_no << endl;
            current = current->next_ogr;
            sayac++;
        }
    }
};

void ogr_listesini_yazdir(Ogrenci_Listesi& o){
    cout << "\tOgrenci Listesi" << endl;
    cout << "________________________________" << endl;
    o.ogrenci_listele();
    cout << "________________________________" << endl;

}


int main(){
    Ogrenci_Listesi o;
    o.ogrenci_ekle(202503049);
    o.ogrenci_ekle(202503050);
    o.ogrenci_ekle(202503051);
    o.ogrenci_ekle(202503058);

    ogr_listesini_yazdir(o);
    o.ogrenci_sil(202503051);
    ogr_listesini_yazdir(o);


    return 0;
}