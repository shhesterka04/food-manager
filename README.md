# food-manager
## 1. Описание задачи
### 1.1 Краткое описание
«А чего бы поесть?» - вопрос, который волнует многих. Из-за того, что уже
на этом этапе возникают трудности, люди предпочитают купить или
заказать готовую пищу. А это будет очень вредно для здоровья или для
кошелька. Поэтому было бы удобно иметь приложение, которое будет в
себе иметь достаточно большую базу блюд со списком рецептов и
ингредиентов, необходимых для готовки, которое могло еще само
подбирать наиболее подходящие комбинации блюд на день, чтобы
поддерживаться подходящего курса питания, даже не думая об этом: кто-то
хочет похудеть, кто-то – набрать массу, а кому-то нужно просто примерно
сохранять свой вес.
### 1.2 Потенциальный круг пользователей
Люди, которые хотят хорошо питаться, но не хотят много думать над этим,
но денег не так много, чтобы брать готовую еду: студенты, жители регионов
### 1.3. Основные возможности и функции ПО
1. Прохождение опроса и регистрация в приложении, после которого
вычисляется оптимальный объем калорий, белков, жиров и углеводов на
день
2. Возможность войти в уже созданный профиль
3. Большая база с более чем 500 рецептами, взятыми с сайта Eda.ru
4. Фильтрация рецептов по БЖУ, калориям
5. Генерирование рациона на 3 дня, который не будет повторяться на
протяжении примерно 4–5 месяцев
## 2. Техническое задание
Создать многопользовательское десктопное приложение, которое умеет
подбирать оптимальный рацион питания на неделю на основе полученных
данных из опроса пользователя. Зная рост, пол, вес и т.д., программа должна
вычислять по формулам необходимое количество калорий, белков, жиров и
углеводов. Каждый раз рацион должен генерироваться новый: не должно
быть 1 оптимального рациона, который будет предлагаться каждый раз.
Разработать удобный интерфейс приложения. Создать базу данных
рецептов, которая будет включать подробные описания и сведения о
питании для каждого рецепта. Разрешить пользователям фильтровать
рецепты по требованиям. Возможность повторно авторизироваться
пользователям для входа в приложение с помощью записи данных в Базу
данных.
База данный будет реализована в SQLite, GUI будет сделан с помощью
библиотеки Qt
## 3. Пользовательская инструкция
1. При запуске программы перед пользователем появляется поле
авторизации в приложение.
![image](https://github.com/shhesterka04/food-manager/assets/88100981/842ee4f7-4d7c-4eda-bce7-002c9f87d54d)
![image](https://github.com/shhesterka04/food-manager/assets/88100981/b119e0b3-9e37-472d-b554-8739a773307b)
2. Вы можете создать свой собственный профиль.
Обратите внимание, для корректной работы программы на поля «Возраст»,
3. После успешной авторизации будет доступно само приложение.
Приложение состоит из 3 элементов: «Конструктор», «Рецепты» и
«Профиль».
В профиле вы можете увидеть свои данные и ознакомиться с
рекомендациями по питанию.
![image](https://github.com/shhesterka04/food-manager/assets/88100981/4f6f50b9-de97-46e3-be4b-2615144e8f2d)
5. В рецептах вы можете посмотреть весь перечень доступных блюд, которые есть в базе данных, а также воспользоваться фильтрами
поиска по калориям, белкам, жирам и углеводам
![image](https://github.com/shhesterka04/food-manager/assets/88100981/3a08660f-2607-4d1d-839e-aa214a69a75e)
6. При двойном нажатии на любое из блюд в списке открывается окно с
рецептов, ингредиентами для приготовления и энергетическая ценность
блюда
![image](https://github.com/shhesterka04/food-manager/assets/88100981/e4fe0ed4-06f2-4c84-b9d7-07776cc84a70)
8. В поле «Конструктор» же находится центральная часть проекта. Целью было сделать максимально простое для пользователя
приложение, поэтому там есть всего 1 кнопка «сгенерировать рацион». На
самом деле, кнопок 10 – на каждый прием пищи можно нажать и
ознакомиться с ингредиентами и способом приготовления. Иногда может
генерироваться некорректный рацион из-за наличия в базе данных десертов
и подготовительных рецептов (теста для выпечки, домашний майонез). В
таких случаях нужно сгенерировать рацион еще раз.
![image](https://github.com/shhesterka04/food-manager/assets/88100981/c8bf3d70-714e-462b-97da-35be213477b8)

## 4. Инструкция по сборке
Репозиторий с исходным кодом: https://github.com/shhesterka04/food-manager
Требования для сборки и использования проекта:
1. CMake минимальной версии 3.14
2. Язык С++ стандарта 17.
3. Компилятор MSVC 2019
4. Qt5
### Инструкция:
1. Устанавливаем Qt v.5 и CMake
2. Клонируем репозиторий в любую директорию ПК
3. Запускаем командную строку и пишем следующие команды:
```
cmake -S (Путь до скопированного репозитория) -B (Путь до папки
для сборки)
cmake --build (Путь до папки для сборки) --config Release
cmake --install (Путь до папки для сборки) --prefix (Путь до
папки, где будет установлено приложение)
```
