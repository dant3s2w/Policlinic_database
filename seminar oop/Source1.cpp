
struct Policlinic {
    char* fam;
    char* name;
    int specialty; // 1 - ��������, 2 - ���������, 3 - ����������

};

// ������� ��� ���������� ������ ����� � ������ .
Policlinic* add_medic(Policlinic* arr, int& size) {
    // ������� ��������� ���������� ��� �������� ������.
    if (size == 0) {
        size++;
        Policlinic tmp;
        printf("������� ������� ������ �����: ");
        char fam[100];
        scanf("%s", &fam);
        // �������� ������ ��� ������� � �������� � ��� �������� �� ��������� ����������.
        tmp.fam = new char[strlen(fam) + 1];
        strcpy(tmp.fam, fam);

        printf("\n ������� ��� ������ �����: ");
        char name[100];
        scanf("%s", &name);
        tmp.name = new char[strlen(name) + 1];
        strcpy(tmp.name, name);

        printf("\n ������� ��� ������ �����(1 - ��������, 2 - ���������, 3 - ����������): ");
        int type;
        scanf("%d", &type);
        tmp.specialty = type;

        // ��������� ������ ����� � ����� �������.
        arr[size - 1] = tmp;
        delete tmp.fam, tmp.name;
        return arr;
    }
    else {
        Policlinic* tmp = new Policlinic[++size];


        //std::copy(arr, arr + std::min(size - 1, size), tmp);
        for (int i = 0; i < size - 1; i++) {
            tmp[i] = arr[i];
        }
        delete[] arr;
        arr = tmp;
        tmp = NULL;

        printf("������� ������� ������ �����: ");
        char fam[100];
        scanf("%s", &fam);
        // �������� ������ ��� ������� � �������� � ��� �������� �� ��������� ����������.
        arr[size - 1].fam = new char[strlen(fam) + 1];
        strcpy(arr[size - 1].fam, fam);

        printf("\n ������� ��� ������ �����: ");
        char name[100];
        scanf("%s", &name);
        arr[size - 1].name = new char[strlen(name) + 1];
        strcpy(arr[size - 1].name, name);

        printf("\n ������� ��� ������ �����(1 - ��������, 2 - ���������, 3 - ����������): ");
        int type;
        scanf("%d", &type);
        arr[size - 1].specialty = type;

        return arr;
    }
}

// ������� ��� ���������� ���������� 
void print_medics(Policlinic* arr, int size) {
    // �������� ��������� �������.
    printf("�������\t���\t��� �����\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t", arr[i].fam);
        printf("%s\t", arr[i].name);
        printf("%d\n", arr[i].specialty);
    }
}


void find_medic(Policlinic* arr, int size, char* surname, char* name) {
    // ���������� ��� ������������� � ���� ���������� �� ������� � �����.
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].fam, surname) == 0 && strcmp(arr[i].name, name) == 0) {
            printf("���� �%d - ", i + 1);
            switch (arr[i].specialty) {
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
            return;
        }
    }
}

void find_type_medic(Policlinic* arr, int size, int specialty) {
    Policlinic* tmp = new Policlinic[size];
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i].specialty == specialty) {
            tmp[count] = arr[i];
            count++;
        }
    }

    cout << "�������\t���\n";
    for (int i = 0; i < count; i++) {
        cout << tmp[i].fam << '\t';
        cout << tmp[i].name << '\n';
    }
    // ����������� ������, ���������� ��� ��������� ������.
    delete[] tmp;
}