#ifndef ASM_H
#define ASM_H

#ifdef _LANGUAGE_ASSEMBLY

#define LEAF(x)                 \
    x:                         ;\
    .globl x                   ;\
    .type x, @function         ;\
        .ent x, 0              ;\
        .frame $29, 0, $31
// .frame has to use $29 and $31 because egcs doesn't like $sp and $ra

#define END(x)                  \
    .size x, . - x             ;\
    .end x

#define SYM_START(x)            \
    .align 2                   ;\
    .globl x                   ;\
    .type	 x, @object        ;\
    x:

#define SYM_END(x)              \
    .size x, . - x

#define EXPORT(x)               \
    .globl  x                  ;\
    x:

#define ABS(x, y)               \
    .globl  x                  ;\
    x = y

#define LA(dst, address) \
    lui         dst, %hi(address); \
    addiu       dst, dst, %lo(address)

#if !__IS_OLD_COMP__

/* Float register aliases */

.set $fv0,          $f0
.set $fv0f,         $f1
.set $fv1,          $f2
.set $fv1f,         $f3
.set $ft0,          $f4
.set $ft0f,         $f5
.set $ft1,          $f6
.set $ft1f,         $f7
.set $ft2,          $f8
.set $ft2f,         $f9
.set $ft3,          $f10
.set $ft3f,         $f11
.set $fa0,          $f12
.set $fa0f,         $f13
.set $fa1,          $f14
.set $fa1f,         $f15
.set $ft4,          $f16
.set $ft4f,         $f17
.set $ft5,          $f18
.set $ft5f,         $f19
.set $fs0,          $f20
.set $fs0f,         $f21
.set $fs1,          $f22
.set $fs1f,         $f23
.set $fs2,          $f24
.set $fs2f,         $f25
.set $fs3,          $f26
.set $fs3f,         $f27
.set $fs4,          $f28
.set $fs4f,         $f29
.set $fs5,          $f30
.set $fs5f,         $f31

#endif

#endif

#define BOOT_STACK_SIZE 0x2000

#endif