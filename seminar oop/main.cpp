#include "main.h"
using namespace std;







int main() {
    setlocale(LC_ALL, "Russian");
    FILE *fp;
    fp = fopen("Medic_oop.txt", "a+");
   
    if (fp == NULL)
    {
        printf("Не удалось открыть файл");
        return 0;
    }
    else { printf("все работает\n"); }

    
    printf("\n------------------------------------------------------------------------------------------------------------\n");
    Policlinic* arr = new Policlinic[1]; // Создаем массив для хранения (происходит копирование указателя, потому новую память можно присвоить только через return)
    data_base BASA;
    data_base* upd_base = new data_base[1];
    BASA.size = 0;

    //int size = 0; // Текущий размер массива.
    char buff[100];
    char fam[100];
    char name[100];
    int type, t;
    bool ok = false;

    //ввод данных из файла в массив поликлиник и контроль количества введенных данных
    while (fscanf(fp, "%s%s%d",
        fam, 
        name, 
        &type) == 3) { 
        if (BASA.size == 0) {
            BASA.size++;
            Policlinic tmp;
            // Выделяем память для фамилии и копируем в нее значение из временной переменной.
            tmp.fam = new char[strlen(fam) + 1];
            strcpy(tmp.fam, fam);

            tmp.name = new char[strlen(name) + 1];
            strcpy(tmp.name, name);

            tmp.specialty = type;

            // Добавляем нового врача в конец массива.
            arr[BASA.size - 1] = tmp;
            delete tmp.fam, tmp.name;
        }
        else {
            Policlinic* tmp = new Policlinic[++BASA.size];

            for (int i = 0; i < BASA.size - 1; i++) {
                tmp[i] = arr[i];
            }
            delete[] arr;
            arr = tmp;
            tmp = NULL;

            arr[BASA.size - 1].fam = new char[strlen(fam) + 1];
            strcpy(arr[BASA.size - 1].fam, fam);

            arr[BASA.size - 1].name = new char[strlen(name) + 1];
            strcpy(arr[BASA.size - 1].name, name);

            arr[BASA.size - 1].specialty = type;

        }
    }
    fclose(fp);
    BASA.arr = arr;
    arr = NULL;

    // Перебираем все возможные действия.
    while (true) {
        printf("Выберите действие: \n");
        printf("1 - Добавить нового медика\n");
        printf("2 - Удалить медика\n");
        printf("3 - Распечатать информацию о медиках\n");
        printf("4 - Найти медика по имени и фамилии\n");
        printf("5 - Найти всех медиков по типу лечения\n");
        printf("6 - Выход\n");
        int choice; // Выбор пользователя.
        scanf("%d", &choice);
        printf("\n------------------------------------------------------------------------------------------------------------\n");
        // В зависимости от выбора пользователя выполняем соответствующее действие.
        switch (choice) {
        case 1:
            BASA = add_medic(BASA);
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            break;
        case 2:
            BASA = delete_medic(BASA);
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            break;
        case 3:
            print_medics(BASA);
            printf("\n\n------------------------------------------------------------------------------------------------------------\n");
            break;
        case 4:
            printf("Введите фамилию медика: ");
            char surname[100];
            scanf("%s", &surname);
            printf("Введите имя медика: ");
            char name[100];
            scanf("%s", &name);
            // Выполняем поиск и выводим результаты на экран.
            t = find_medic(BASA, surname, name);
            printf("\n");
            break;
        case 5:
            printf("Выберите тип врача:\n 1 - терапевт\n 2 - кардиолог\n 3 - стоматолог\n");
            int type;
            ok = false;
            //проверка корректности ввода данныых
            while (!ok) {
                scanf("%d", &type);
                if (type > 3 || type < 1) {
                    printf("Некорректный ввод данных, введите еще раз!\n");
                    scanf("%*[^\n]");
                }
                else ok = true;
            }
            printf("\n");
            // Выполняем поиск и выводим результаты на экран.
            delete[] upd_base;
            upd_base = find_type_medic(BASA, type);
            
            if (upd_base == NULL) {
                printf("Такого врача нет!\n");
            }
            else {
                print_medics(*upd_base);
            }
            printf("\n\n------------------------------------------------------------------------------------------------------------\n");
            break;
        case 6:
            // Выходим из программы.
            printf("До свидания!\n");
            fp = fopen("Medic_oop.txt", "w");
            //запись данных в очищенный файл
            for (int i = 0; i < BASA.size; i++) {
                fprintf(fp, "%s %s %d\n", BASA.arr[i].fam, BASA.arr[i].name, BASA.arr[i].specialty);
            }
            delete[] BASA.arr;
            
            fclose(fp);
            return 0;
        default:
            // Выводим сообщение об ошибке, если пользователь ввел неверный номер команды.
            printf("Неверный номер команды!\n");
            printf("\n------------------------------------------------------------------------------------------------------------\n");
            //очистка буфера
            scanf("%*[^\n]");
            break;
        }
    }
}

