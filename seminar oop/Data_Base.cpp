#include "Data_Base.h"
// Функция для добавления нового врача в массив .

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

        printf("Введите фамилию нового врача: ");
        char fam[100];
        scanf("%s", &fam);
        // Выделяем память для фамилии и копируем в нее значение из временной переменной.
        base.arr[base.size - 1].fam = new char[strlen(fam) + 1];
        strcpy(base.arr[base.size - 1].fam, fam);

        printf("\n Введите имя нового врача: ");
        char name[100];
        scanf("%s", &name);
        base.arr[base.size - 1].name = new char[strlen(name) + 1];
        strcpy(base.arr[base.size - 1].name, name);

        printf("\n Введите тип нового врача(1 - терапевт, 2 - кардиолог, 3 - стоматолог): ");
        int type;
        while (!ok) {
            scanf("%d", &type);
            if (type > 3 || type < 1) {
                printf("Такого типа врача не существует, попробуйте еще раз!\n\n");
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
        printf("База данных пуста, удаление сотрудников невозможно\n");
        return base;
    }
    else {
        printf("Выберите сотрудника, которого хотите удалить\n");
        printf("Введите фамилию медика: ");
        char surname[100];
        scanf("%s", &surname);
        printf("Введите имя медика: ");
        char name[100];
        scanf("%s", &name);
        // Выполняем поиск и выводим результаты на экран.
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
    // Перебираем все преподаватели и ищем совпадения по фамилии и имени.
    bool ok = false;
    for (int i = 0; i < base.size; i++) {
        if (strcmp(base.arr[i].fam, surname) == 0 && strcmp(base.arr[i].name, name) == 0) {
            printf("Врач №%d - ", i + 1);
            ok = true;
            switch (base.arr[i].specialty) {
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
            return i;
        }
    }
    if (!ok)    printf("Такого врача нет!\n");
    return 0;
}
data_base* find_type_medic(data_base base, int specialty) {
    Policlinic* tmp = new Policlinic[base.size];
    int count = 0;
    //поиск совпадений
    for (int i = 0; i < base.size; i++) {
        if (base.arr[i].specialty == specialty) {
            tmp[count] = base.arr[i];
            count++;
        }
    }
    //если никого не нашли, то ноль
    if (count == 0) {
        return NULL; 
    }
    data_base* new_base = new data_base[count];
    new_base -> size = count;
    new_base->arr = tmp;

    // Освобождаем память, выделенную под временный массив.
    tmp = NULL;
    return new_base;
}
void print_medics(data_base base) {
    // Печатаем заголовок таблицы.
    printf("Фамилия\tИмя\tТип врача\n");
    for (int i = 0; i < base.size; i++) {
        printf("%s\t", base.arr[i].fam);
        printf("%s\t", base.arr[i].name);
        printf("%d\n", base.arr[i].specialty);
    }
}
