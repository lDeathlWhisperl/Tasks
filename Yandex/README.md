# [Yandex] "Через тернии к клиенту"

![Снимок экрана (32)](https://user-images.githubusercontent.com/62991413/188958431-f307edef-38b5-4357-b793-24076fb096e7.png)

<p>
  Известная компания Тындекс идёт в ногу со временем — с началом активных космических перелётов в компании открылся сервис Тындекс.Ракетакси: пользователю необходимо
  лишь указать координаты начала и конца перелёта, после чего за ним вылетит персональная ракета.
  По сути любой заказ можно описать в виде событий четырёх типов:
</p>
<ul>
  <li> A (accepted)  - заказ принят в работу (ракета вылетела за клиентом);</li>
  <li> B (boarding)  - клиент сел в ракету;</li>
  <li> S (success)   - заказ успешно завершён (клиент вышел на планете назначения);</li>
  <li> C (cancelled) - заказ отменён.</li>
</ul>
<p>
Все происходящие с ракетами события отправляются на сервера, где сразу логируются. Вот только из-за проблем со связью (метеоритные потоки, вспышки на звездах и т.д.) отправка событий иногда затягивается, из-за чего записи в получившемся логе могут идти не по порядку.
Гарантируется, что все описанные в логе события задают один из следующих сценариев:
</p>
<ul>
  <li> A - B - S </li>
  <li> A - B - C </li>
  <li> A - C     </li>
</ul>
<p>
Вам, как главному аналитику (и по совместительству главному программисту) ракетопарка, необходимо исследовать лог за прошедший год и определить для каждой ракеты суммарное время движения (в минутах) в течение заказов.
В каждый момент времени ракета выполняет только один заказ. Будем считать, что каждая ракета в каждый момент времени:

или стоит на месте в ожидании заказа,
или перемещается по космосу, выполняя заказ.
Движение начинается после принятия заказа и завершается после отмены или завершения заказа. За одну минуту не может произойти несколько событий, связанных с одной и той же ракетой.
</p>

## Формат ввода

<p>
  В первой строке дано целое число <b><i>N (2 ≤ N ≤ 200000)</b></i> — количество записей в логе. Следующие <b><i>N</b></i> строк содержат записи в логе в формате 
  <b><i>day hour minute id status</i></b>:
</p>
<ul>
  <li> <b><i> day (1 ≤ d ≤ 365)   </b></i> — номер дня (сквозная нумерация с начала календарного года);</li>
  <li> <b><i> hour (0 ≤ h < 24)   </b></i> — часы;</li>
  <li> <b><i> minute (0 ≤ m < 60) </b></i> — минуты;</li>
  <li> <b><i> id (0 ≤ id ≤ 109)   </b></i> — уникальный идентификатор ракеты; </li>
  <li> <b><i> status ∈ {A,B,S,C}  </b></i> — буква, обозначающая тип события.</li>
</ul>

## Формат вывода

<p>
В единственной строке выведите через пробел суммарное время движения на заказах для каждой упомянутой в логе ракеты. Данные необходимо выводить в порядке возрастания идентификаторов ракет.
</p>

## Пример

<p>
  8                 <br>
  50 7 25 3632 A    <br>
  14 23 52 212372 S <br>
  15 0 5 3632 C     <br>
  14 21 30 212372 A <br>
  50 7 26 3632 C    <br>
  14 21 30 3632 A   <br>
  14 21 40 212372 B <br>
  14 23 52 3632 B   <br>
  <br>
  Вывод: 156 142
</p>

![Снимок экрана (34)](https://user-images.githubusercontent.com/62991413/188962407-475e2b97-5c4a-4ee9-8443-5642188f5c21.png)

