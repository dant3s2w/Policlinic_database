
struct Policlinic {
    char* fam;
    char* name;
    int specialty; // 1 - терапевт, 2 - кардиолог, 3 - стоматолог

};

// Функция для добавления нового врача в массив .
Policlinic* add_medic(Policlinic* arr, int& size) {
    // Создаем временную переменную для хранения данных.
    if (size == 0) {
        size++;
        Policlinic tmp;
        printf("Введите фамилию нового врача: ");
        char fam[100];
        scanf("%s", &fam);
        // Выделяем память для фамилии и копируем в нее значение из временной переменной.
        tmp.fam = new char[strlen(fam) + 1];
        strcpy(tmp.fam, fam);

        printf("\n Введите имя нового врача: ");
        char name[100];
        scanf("%s", &name);
        tmp.name = new char[strlen(name) + 1];
        strcpy(tmp.name, name);

        printf("\n Введите тип нового врача(1 - терапевт, 2 - кардиолог, 3 - стоматолог): ");
        int type;
        scanf("%d", &type);
        tmp.specialty = type;

        // Добавляем нового врача в конец массива.
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

        printf("Введите фамилию нового врача: ");
        char fam[100];
        scanf("%s", &fam);
        // Выделяем память для фамилии и копируем в нее значение из временной переменной.
        arr[size - 1].fam = new char[strlen(fam) + 1];
        strcpy(arr[size - 1].fam, fam);

        printf("\n Введите имя нового врача: ");
        char name[100];
        scanf("%s", &name);
        arr[size - 1].name = new char[strlen(name) + 1];
        strcpy(arr[size - 1].name, name);

        printf("\n Введите тип нового врача(1 - терапевт, 2 - кардиолог, 3 - стоматолог): ");
        int type;
        scanf("%d", &type);
        arr[size - 1].specialty = type;

        return arr;
    }
}

// Функция для распечатки информации 
void print_medics(Policlinic* arr, int size) {
    // Печатаем заголовок таблицы.
    printf("Фамилия\tИмя\tТип врача\n");
    for (int i = 0; i < size; i++) {
        printf("%s\t", arr[i].fam);
        printf("%s\t", arr[i].name);
        printf("%d\n", arr[i].specialty);
    }
}


void find_medic(Policlinic* arr, int size, char* surname, char* name) {
    // Перебираем все преподаватели и ищем совпадения по фамилии и имени.
    for (int i = 0; i < size; i++) {
        if (strcmp(arr[i].fam, surname) == 0 && strcmp(arr[i].name, name) == 0) {
            printf("Врач №%d - ", i + 1);
            switch (arr[i].specialty) {
            case 1:
                printf("терапевт\n");
                break;
            case 2:
                printf("кардиолог\n");
                break;
            case 3:
                printf("стоматолог\n");
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

    cout << "Фамилия\tИмя\n";
    for (int i = 0; i < count; i++) {
        cout << tmp[i].fam << '\t';
        cout << tmp[i].name << '\n';
    }
    // Освобождаем память, выделенную под временный массив.
    delete[] tmp;
}