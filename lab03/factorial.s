.globl factorial

.data
n: .word 8

.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
    bne a0 x0 calculate
    addi a0 x0 1
    jr ra
calculate:
    addi sp sp -8
    sw a0 0(sp)
    sw ra 4(sp)
    addi a0 a0 -1
    jal factorial
    lw a1 0(sp)
    lw ra 4(sp)
    addi sp sp 8
    mul a0 a0 a1
    jr ra