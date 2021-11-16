<h1 align="center">
	42cursus' push_swap
</h1>

<p align="center">
	<b><i>Development repo for 42cursus' push_swap project</i></b><br>
	For further information about 42cursus and its projects, please refer to <a href="https://github.com/psdiaspedro?tab=repositories"><b>my repo</b></a>.
</p>

# 🗣️ About
Push_swap is a sorting algorithm. The goal of this project is sorting data using two stacks, a limited set of instructions and using
the lowest possible numbers of actions. 

In the end, the main stack must be sorted and aux stack must be empty.

![DemoMinitalk](https://github.com/psdiaspedro/pushSwap-42Cursus/blob/master/ps.gif)

## 📋 Moves allowed 

- `sa` : swap the first 2 elements at the top of stack a (do nothing if there is only one or no elements).
- `sb` : swap the first 2 elements at the top of stack b (do nothing if there is only one or no elements).
- `ss` : `sa` and `sb` at the same time.
- `pa` : take the first element at the top of b and put it at the top of a. Do
nothing if b is empty.
- `pb` : take the first element at the top of a and put it at the top of b. Do
nothing if a is empty.
- `ra` : shift up all elements of stack a by 1. The first element becomes
the last one.
- `rb` : shift up all elements of stack b by 1. The first element becomes the last one.
- `rr` : `ra` and `rb` at the same time.
- `rra` : shift down all elements of stack a by 1. The last element becomes the first one.
- `rrb` : shift down all elements of stack b by 1. The last element becomes the first one.
- `rrr` : `rra` and `rrb` at the same time.
<br />

## 🛠️ Compiling
Using Makefile you will create ./push_swap
```
make
```

## ✏️ Basic running 
An exemple with 10 random numbers (0 to 99)
```
./push_swap 66 11 24 1 0 -30 44 8 27 16
```

## ✏️ Running python visualizer 
Obs: to run the visualizer you must have python3 (you can see the vizualizer's repo here: https://github.com/o-reo/push_swap_visualizer).

An exemple with 100 random numbers (0 to 99)
```
python3 pyviz.py `ruby -e "puts (0..99).to_a.shuffle.join(' ')"`
```
#### More about School 42 you can find here: https://en.wikipedia.org/wiki/42_(school)
