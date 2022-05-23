# minishell
## Цель данного проекта написать свою оболочку имитирующую работу bash. 
### Введение
    
Были времена, когда все разработчики сходились во мнении, что общение с компьютером с помощью переключателя 1/0 серьезно раздражало. Вполне логично, что им пришла в голову идея создания программного обеспечения для общения с компьютером с помощью интерактивных строк команд на языке, несколько близким к человеческому. Благодаря Minishell вы сможете путешествовать во времени и возвращаться к проблемам когда люди сталкивались с тем, что Окон не существовало.

### Основная часть
Ваша оболочка должна:
- Отображение <b>приглашения</b> при ожидании новой команды.
- У вас есть <b>история</b> работы.
- Найдите и запустите нужный исполняемый файл (на основе переменной `PATH` или используя относительный или абсолютный путь).
- Не используйте более <b>одной глобальной переменной</b>. Подумай об этом. Вам придется объяснить его назначение.
- Не интерпретируйте незакрытые кавычки или специальные символы, которые не требуются субъекту, такие как `\` (обратная косая черта) или `;` (точка с запятой).
- <b>`’`</b> (одинарная кавычка), которая должна препятствовать интерпретации оболочкой метасимволов в последовательности кавычек.
- <b>`"`</b> (двойная кавычка), которая должна препятствовать интерпретации оболочкой метасимволов в последовательности кавычек, за исключением `$` (знака доллара).
- Реализовать перенаправления:
    - `<` должен перенаправлять ввод.
    - `>` следует перенаправить вывод.
    - `<<` следует задать разделитель, а затем читать входные данные до тех пор, пока не появится строка, содержащая разделитель. Тем не менее, он не должен обновлять историю!
    - `>>` должен перенаправлять вывод в режиме добавления.
- Реализуйте <b>пайпы</b> (`|` символ). Выход каждой команды в конвейере соединяется с входом следующей команды через канал.
- Обрабатывать <b>переменные окружения</b> (`$`, за которыми следует последовательность символов), которые должны расширяться до их значений.
- `$?` который должен расшириться до состояния выхода самого последнего выполненного конвейера переднего плана.
- Обработайте сигналы `Ctrl-C`, `Ctrl-D` и `Ctrl-\`, которые должны вести себя как в bash.
- В интерактивном режиме:
    - `Ctrl-C` отображает новое приглашение в новой строке.
    - `Ctrl-D` выходит из оболочки.
    - `Ctrl-\` ничего не делает.
- Ваша оболочка должна реализовать следующие <b>встроенные</b> функции:
    - `echo` с опцией `-n`
    - `cd` только с относительным или абсолютным путем
    - `pwd` без опций
    - `export` без опций
    - `unset` без опций
    - `env` без опций или аргументов
    - `exit` без опций

Функция readline() может привести к утечке памяти. Вам не нужно их чинить. Но это <b>не значит, что ваш собственный код, да, код, который вы написали, может иметь утечки памяти</b>.

### Бонусная часть
Должны быть реализованы:
- `&&` и `||` со скобками для приоритетов.
- Подстановочные знаки `*` должны работать для текущего рабочего каталога.

Тестеры
-------
- [первый](https://github.com/alchrist42/msh_tester)
- [второй](https://pypi.org/project/minishell-test/#description)
<img width="766" alt="image" src="https://user-images.githubusercontent.com/58044383/169036722-1a7d57c0-e7c6-4b50-99db-edb5e6e648d6.png">

Чеклист
-------
[checklist](https://github.com/mharriso/school21-checklists/blob/master/ng_3_minishell.pdf)
<img width="1014" alt="image" src="https://user-images.githubusercontent.com/58044383/169034673-13408430-65ac-4e05-a69e-eb4c023f6262.png">

<details>
<summary>Полезные материалы</summary>
    
Полезные материалы
------------------
- Чтиво по minishell
    - "[Linux API исчерпывающее руководство](https://vk.com/wall-51126445_46377#:~:text=%D0%90%D0%BD%D0%B3%D0%BB%D0%BE%D1%8F%D0%B7%D1%8B%D1%87%D0%BD%D0%BE%D0%B5%20%D0%B8%D0%B7%D0%B4%D0%B0%D0%BD%D0%B8%D0%B5%20%D1%8D%D1%82%D0%BE%D0%B9%20%D0%BA%D0%BD%D0%B8%D0%B3%D0%B8%20%D0%B2%D1%8B%D1%88%D0%BB%D0%BE%20%D0%B2%20%D0%BA%D0%BE%D0%BD%D1%86%D0%B5%202010%20%D0%B3%D0%BE%D0%B4%D0%B0)" 2019 Майкл Керриск - книга по работе линукса.
    - [гайд](https://github.com/eLEGIJA/minishell)
    - еще [гайд](https://github.com/Ukio-G/minishell/blob/master/doc.md)
    - описание библиотеки [`readline`](https://russianblogs.com/article/7614321785/)
    - туториал по [termcap](https://docs.google.com/document/d/1OzX0XRMcIUvCoE5ZTidod0K6yN3Kfs0wH0k-jTz45Lk/edit)
    - управление [терминалом](https://ejudge.ru/study/3sem/term.pdf)
- Видео лекции от 
    - [weambros](https://www.youtube.com/watch?v=Um3pzuee-4Y&ab_channel=AlexanderShorshin-studentof21school)
    - [rdrizzle](https://www.youtube.com/watch?v=A7ccmRSn7JY&list=PLUJCSGGiox1R4wwUO0hS899uT02XDQIc_&ab_channel=Edu_events_mow)
    - [imicah](https://www.youtube.com/watch?v=7B6o2YyvIKw&list=PLUJCSGGiox1R4wwUO0hS899uT02XDQIc_&index=4&ab_channel=Edu_events_mow)
    - еще [лекция](https://www.youtube.com/watch?v=i49JO5YA08s&list=PLUJCSGGiox1R4wwUO0hS899uT02XDQIc_&index=5&ab_channel=%D0%90%D0%BB%D0%B5%D0%BA%D1%81%D0%B0%D0%BD%D0%B4%D1%80%D0%90%D1%80%D1%85%D0%B8%D0%BF%D0%BE%D0%B2)
- [Кейсы](https://docs.google.com/spreadsheets/d/1RPxSWKzRELfAirkaLeqqzoEArkaq9Vy7tTEHEnamlgA/edit#gid=0) для слома minishell 
- Как использовать цвета чтобы `readline` правильно [работал](https://github.com/tlucanti/minishell/blob/master/inc/color.h)
- Прочтать man по `printf`, `malloc`, `free`, `write`, `access`, `open`, `read`, `close`, `fork`, `wait`, `waitpid`, `wait3`, `wait4`, `signal`, `sigaction`, `sigemptyset`, `sigaddset`, `kill`, `exit`, `getcwd`, `chdir`, `stat`, `lstat`, `fstat`, `unlink`, `execve`, `dup`, `dup2`, `pipe`, `opendir`, `readdir`, `closedir`, `strerror`, `perror`, `isatty`, `ttyname`, `ttyslot`, `ioctl`, `getenv`, `tcsetattr`, `tcgetattr`, `tgetent`, `tgetflag`, `tgetnum`, `tgetstr`, `tgoto`, `tputs`
    
</details>
