		shift_sp 1
		push_const EXIT
		push_reg fp
		push_reg sp
		pop_reg fp
		jump main
EXIT:
		exit
outprint:
outprint_start:
		push_reg fp
		push_const 1
		add
		fetch
		push_reg sp
		fetch
		push_reg fp
		push_const 1
		add
		fetch
		fetch
		push_const 10
		add
		assign
		fetch
		shift_sp -1
outprint_final:
		push_reg fp
		pop_reg sp
		pop_reg fp
		pop_reg pc
outprint_end:
main:
main_start:
		shift_sp 12
		push_reg fp
		push_const 12
		add
		fetch
		push_reg sp
		fetch
		push_const 10
		assign
		fetch
		shift_sp -1
		push_reg fp
		push_const 1
		add
		push_const 0
		push_const 1
		mul
		add
		push_reg sp
		fetch
		push_const 97
		assign
		fetch
		shift_sp -1
		push_reg fp
		push_const 1
		add
		push_const 1
		push_const 1
		mul
		add
		push_reg sp
		fetch
		push_const 98
		assign
		fetch
		shift_sp -1
		push_reg fp
		push_const 1
		add
		push_const 2
		push_const 1
		mul
		add
		push_reg sp
		fetch
		push_const 99
		assign
		fetch
		shift_sp -1
		shift_sp 1
		push_const label_0
		push_reg fp
		push_reg fp
		push_const 12
		add
		fetch
		push_reg sp
		push_const -1
		add
		pop_reg fp
		jump outprint
label_0:
		shift_sp -1
		push_reg fp
		push_const 11
		add
		push_reg sp
		fetch
str_0. string "car"
		assign
		fetch
		shift_sp -1
		push_reg fp
		push_const 1
		add
		push_reg fp
		push_const 1
		add
		write_string
str_1. string "\n"
		push_const str_1
		write_string
		push_reg fp
		push_const 11
		add
		push_const str_0
		write_string
str_2. string "\n"
		push_const str_2
		write_string
main_final:
		push_reg fp
		pop_reg sp
		pop_reg fp
		pop_reg pc
main_end:
Lglob.  data 0
