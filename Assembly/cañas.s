.data
    myArray: .space 16
    newLine: .asciiz  "\n"

.text
    main:

    addi $t2,$zero,8  #Cargo la constante 8 en el registro $t2

    addi $s0, $zero,4
    addi $s1, $zero,10
    addi $s2, $zero,12
    addi $s3, $zero,20

    sw $s0,myArray($t0)
     addi $t0,$t0,4
    sw $s1,myArray($t0)
     addi $t0,$t0,4
    sw $s2,myArray($t0)


    addi $t0,$zero,0




    while:
        beq $t0,16,exit

        lw $t6,myArray($t0)  #Cargo el valor del arreglo en t6

        mul $t1,$t6,$t2

        addi $t0,$t0,4 #Corregir el offset cada loop

        #imprimir number
        li $v0,1
        addi $a0,$t1,0
        syscall

        #nuevaLinea
        li $v0,4
        la $a0,newLine
        syscall 


        j while

    exit:
        li $v0,10
        syscall
        jr $ra