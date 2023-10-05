#include "Data_Base.h"
// ������� ��� ���������� ������ ����� � ������ .

data_base add_medic(data_base base) {
    bool ok = false;
    
    if (base.size == 0) {
        base.size++;
    }
    else {
        Policlinic* tmp = new Policlinic[++base.size];


        for (int i = 0; i < base.size - 1; i++) {
            tmp[i] = base.arr[i];
        }
        delete[] base.arr;
        base.arr = tmp;
        tmp = NULL;
    }

        printf("������� ������� ������ �����: ");
        char fam[100];
        scanf("%s", &fam);
        // �������� ������ ��� ������� � �������� � ��� �������� �� ��������� ����������.
        base.arr[base.size - 1].fam = new char[strlen(fam) + 1];
        strcpy(base.arr[base.size - 1].fam, fam);

        printf("\n ������� ��� ������ �����: ");
        char name[100];
        scanf("%s", &name);
        base.arr[base.size - 1].name = new char[strlen(name) + 1];
        strcpy(base.arr[base.size - 1].name, name);

        printf("\n ������� ��� ������ �����(1 - ��������, 2 - ���������, 3 - ����������): ");
        int type;
        while (!ok) {
            scanf("%d", &type);
            if (type > 3 || type < 1) {
                printf("������ ���� ����� �� ����������, ���������� ��� ���!\n\n");
                scanf("%*[^\n]");
            }
            else { ok = true; }
        }
        base.arr[base.size - 1].specialty = type;

        return base;
}
data_base delete_medic(data_base base) {
    if (base.size == 1) {
        base.size--;
        Policlinic* tmp = new Policlinic[1];
        delete[] base.arr;
        base.arr = tmp;
        tmp = NULL;
        printf("SUCCESS\n\n");
        return base;
    }
    else if (base.size == 0) {
        printf("���� ������ �����, �������� ����������� ����������\n");
        return base;
    }
    else {
        printf("�������� ����������, �������� ������ �������\n");
        printf("������� ������� ������: ");
        char surname[100];
        scanf("%s", &surname);
        printf("������� ��� ������: ");
        char name[100];
        scanf("%s", &name);
        // ��������� ����� � ������� ���������� �� �����.
        int num = find_medic(base, surname, name);
        std::cout << num << std::endl;
        if (num == 0) {
            return base;
        }
        Policlinic* tmp = new Policlinic[--base.size];
        int j = 0;
        for (int i = 0; i < base.size + 1; i++) {
            if (i == num) {   continue; }
            tmp[j] = base.arr[i];
            j++;
        }
        delete[] base.arr;
        base.arr = tmp;
        tmp = NULL;
        std::cout << base.size;
        for (int i = 0; i < base.size; i++) {
           
        }
        return base;
    }
}

int find_medic(data_base base, char* surname, char* name) {
    // ���������� ��� ������������� � ���� ���������� �� ������� � �����.
    bool ok = false;
    for (int i = 0; i < base.size; i++) {
        if (strcmp(base.arr[i].fam, surname) == 0 && strcmp(base.arr[i].name, name) == 0) {
            printf("���� �%d - ", i + 1);
            ok = true;
            switch (base.arr[i].specialty) {
            case 1:
                printf("��������\n");
                break;
            case 2:
                printf("���������\n");
                break;
            case 3:
                printf("����������\n");
                break;
            }
            return i;
        }
    }
    if (!ok)    printf("������ ����� ���!\n");
    return 0;
}
data_base* find_type_medic(data_base base, int specialty) {
    Policlinic* tmp = new Policlinic[base.size];
    int count = 0;
    //����� ����������
    for (int i = 0; i < base.size; i++) {
        if (base.arr[i].specialty == specialty) {
            tmp[count] = base.arr[i];
            count++;
        }
    }
    //���� ������ �� �����, �� ����
    if (count == 0) {
        return NULL; 
    }
    data_base* new_base = new data_base[count];
    new_base -> size = count;
    new_base->arr = tmp;

    // ����������� ������, ���������� ��� ��������� ������.
    tmp = NULL;
    return new_base;
}
void print_medics(data_base base) {
    // �������� ��������� �������.
    printf("�������\t���\t��� �����\n");
    for (int i = 0; i < base.size; i++) {
        printf("%s\t", base.arr[i].fam);
        printf("%s\t", base.arr[i].name);
        printf("%d\n", base.arr[i].specialty);
    }
}
