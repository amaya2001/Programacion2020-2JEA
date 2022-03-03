

          .data                   # Put Global Data here
Mensaje1:
          .asciiz "Ingrese cadena a convertir:"
Mensaje2:
          .asciiz "Cadena convertida es:"
strInput:
          .space 256
strOutput: 
		  .space 256

#===( Code )=====================================================
          .text                   # User code starts here
#---( main )-----------------------------------------------------
main:
        # Pedir cadena
        la      $a0, Mensaje1
		add	  $v0,$0,4
        syscall
        la      $a0, strInput
		ori	  $v0,$0,8
        syscall
        # verifico que la cadena no esta vacia
		la		$s0, strInput
		la		$s2,strOutput
		lbu		$t0,0($s0)       #$t0 <= Memory [$a0 + Const] 
		addi	$t1,$0,10
		beq		$t0,$t1, exit
		# Recorrer cadena
recorrer:
		# leer caracter a convertir
		lbu		$t0,0($s0)       #$t0 <= Memory [$a0 + Const]
		# compare fin de cadena
		addi	$t1,$0,10
		beq		$t0,$t1, exit2
		# convierte a mayuscula
		addi	$t1,$t0,-32
		# Almaceno el resultado		$t1, 0($s2)
		# incremento contadores
		addi	$s0,$s0,1
		addi	$s2,$s2,1
		# repito el proceso
		j		recorrer
exit2:
        # imprime resultado
        la      $a0, strOutput
		add	  $v0,$0,4
        syscall		
exit:
          li      $v0, 10                 # Code for program exit.
          syscall
# Program ends
          .end

# End of file
