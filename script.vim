function! VisMove(f)
	normal! gv
	call function(a:f)()
endfunction

vnoremap <buffer> a : call VisMove('F')<cr>
