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
		shift_sp 1
str_0. string "abc\n"
		push_const str_0
		write_string
		push_reg fp
		push_const 1
		add
		push_reg sp
		fetch
str_1. string "car"
		assign
		fetch
		shift_sp -1
		push_reg fp
		push_const 1
		add
		push_const str_1
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
