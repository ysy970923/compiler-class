		push_const EXIT
		push_reg fp
		push_reg sp
		pop_reg fp
		jump main
EXIT:
		exit
temp:
temp_start:
		push_reg fp
		push_const -1
		add
		push_const -2
		add
		push_reg fp
		push_const -1
		add
		push_const -1
		add
		push_reg fp
		push_const 1
		add
		fetch
		push_reg fp
		push_const 2
		add
		fetch
		push_reg sp
		push_const 2
		sub
		fetch
		push_reg sp
		push_const 1
		sub
		fetch
		assign
		shift_sp -1
		push_reg sp
		push_const 2
		sub
		fetch
		push_reg sp
		push_const 1
		sub
		fetch
		assign
		shift_sp -1
		shift_sp -2
		jump temp_final
temp_final:
		push_reg fp
		pop_reg sp
		pop_reg fp
		pop_reg pc
temp_end:
main:
main_start:
		shift_sp 4
		push_reg fp
		push_const 1
		add
		push_reg sp
		fetch
		push_const 10
		assign
		fetch
		shift_sp -1
		push_reg fp
		push_const 1
		add
		push_const 1
		add
		push_reg sp
		fetch
		push_const 20
		assign
		fetch
		shift_sp -1
		push_reg fp
		push_const 3
		add
		push_reg fp
		push_const 3
		add
		push_reg fp
		push_const 4
		add
		push_reg fp
		push_const 1
		add
		fetch
		push_reg fp
		push_const 2
		add
		fetch
		push_reg sp
		push_const 2
		sub
		fetch
		push_reg sp
		push_const 1
		sub
		fetch
		assign
		shift_sp -1
		push_reg sp
		push_const 2
		sub
		fetch
		push_reg sp
		push_const 1
		sub
		fetch
		assign
		shift_sp -1
		shift_sp -2
		shift_sp -1
		push_reg fp
		push_const 3
		add
		fetch
		write_int
str_0. string "\n"
		push_const str_0
		write_string
main_final:
		push_reg fp
		pop_reg sp
		pop_reg fp
		pop_reg pc
main_end:
Lglob.  data 0
