# Программирование на языке Си
Вариант 9.

Квадрат с длиной стороны 10, стороны квадрата параллельны осям координат, центр
квадрата в точке (10, -10). 

$i_{0}=10, j_{0}=20, l_{0}=-1$

$i_{k+1}=\left(\left|\max \left(i_{k}(k+5) , j_{k}(k+6)\right)\right|-\left|\min \left(j_{k} (k+7) , l_{k}(k+8)\right)\right|\right) \bmod 20$

$j_{k+1}=\left(3-\operatorname{sign}\left(i_{k}-j_{k}\right)\right)\left|\min \left(i_{k} l_{l}+5 , j_{k} l_{k}-3 , i_{k} j_{k}+6\right)\right| \bmod 25-7$

$l_{k+1}=i_{k} \bmod 10+j_{k} \bmod 10+l_{k} \bmod 10$
