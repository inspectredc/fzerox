#ifndef ASEQ_H
#define ASEQ_H

// control flow commands
#define ASEQ_OP_CONTROL_FLOW_FIRST 0xF2
#define ASEQ_OP_RBLTZ   0xF2
#define ASEQ_OP_RBEQZ   0xF3
#define ASEQ_OP_RJUMP   0xF4
#define ASEQ_OP_BGEZ    0xF5
#define ASEQ_OP_BREAK   0xF6
#define ASEQ_OP_LOOPEND 0xF7
#define ASEQ_OP_LOOP    0xF8
#define ASEQ_OP_BLTZ    0xF9
#define ASEQ_OP_BEQZ    0xFA
#define ASEQ_OP_JUMP    0xFB
#define ASEQ_OP_CALL    0xFC
#define ASEQ_OP_DELAY   0xFD
#define ASEQ_OP_DELAY1  0xFE
#define ASEQ_OP_END     0xFF

// sequence commands
#define ASEQ_OP_SEQ_TESTCHAN        0x00 // low nibble used as argument
#define ASEQ_OP_SEQ_STOPCHAN        0x40 // low nibble used as argument
#define ASEQ_OP_SEQ_SUBIO           0x50 // low nibble used as argument
#define ASEQ_OP_SEQ_LDRES           0x60 // low nibble used as argument
#define ASEQ_OP_SEQ_STIO            0x70 // low nibble used as argument
#define ASEQ_OP_SEQ_LDIO            0x80 // low nibble used as argument
#define ASEQ_OP_SEQ_LDCHAN          0x90 // low nibble used as argument
#define ASEQ_OP_SEQ_RLDCHAN         0xA0 // low nibble used as argument
#define ASEQ_OP_SEQ_LDSEQ           0xB0 // low nibble used as argument
#define ASEQ_OP_SEQ_RUNSEQ          0xC4
#define ASEQ_OP_SEQ_SCRIPTCTR       0xC5
#define ASEQ_OP_SEQ_STOP            0xC6
#define ASEQ_OP_SEQ_STSEQ           0xC7
#define ASEQ_OP_SEQ_SUB             0xC8
#define ASEQ_OP_SEQ_AND             0xC9
#define ASEQ_OP_SEQ_LDI             0xCC
#define ASEQ_OP_SEQ_DYNCALL         0xCD
#define ASEQ_OP_SEQ_RAND            0xCE
#define ASEQ_OP_SEQ_NOTEALLOC       0xD0
#define ASEQ_OP_SEQ_LDSHORTGATEARR  0xD1
#define ASEQ_OP_SEQ_LDSHORTVELARR   0xD2
#define ASEQ_OP_SEQ_MUTEBHV         0xD3
#define ASEQ_OP_SEQ_MUTE            0xD4
#define ASEQ_OP_SEQ_MUTESCALE       0xD5
#define ASEQ_OP_SEQ_FREECHAN        0xD6
#define ASEQ_OP_SEQ_INITCHAN        0xD7
#define ASEQ_OP_SEQ_VOLSCALE        0xD9
#define ASEQ_OP_SEQ_VOLMODE         0xDA
#define ASEQ_OP_SEQ_VOL             0xDB
#define ASEQ_OP_SEQ_TEMPOCHG        0xDC
#define ASEQ_OP_SEQ_TEMPO           0xDD
#define ASEQ_OP_SEQ_RTRANSPOSE      0xDE
#define ASEQ_OP_SEQ_TRANSPOSE       0xDF
#define ASEQ_OP_SEQ_EF              0xEF
#define ASEQ_OP_SEQ_FREENOTELIST    0xF0
#define ASEQ_OP_SEQ_ALLOCNOTELIST   0xF1

// channel commands
#define ASEQ_OP_CHAN_CDELAY         0x00 // low nibble used as argument
#define ASEQ_OP_CHAN_LDSAMPLE       0x10 // low nibble used as argument
#define ASEQ_OP_CHAN_LDCHAN         0x20 // low nibble used as argument
#define ASEQ_OP_CHAN_STCIO          0x30 // low nibble used as argument
#define ASEQ_OP_CHAN_LDCIO          0x40 // low nibble used as argument
#define ASEQ_OP_CHAN_SUBIO          0x50 // low nibble used as argument
#define ASEQ_OP_CHAN_LDIO           0x60 // low nibble used as argument
#define ASEQ_OP_CHAN_STIO           0x70 // lower 3 bits used as argument
#define ASEQ_OP_CHAN_RLDLAYER       0x78 // lower 3 bits used as argument
#define ASEQ_OP_CHAN_TESTLAYER      0x80 // lower 3 bits used as argument
#define ASEQ_OP_CHAN_LDLAYER        0x88 // lower 3 bits used as argument
#define ASEQ_OP_CHAN_DELLAYER       0x90 // lower 3 bits used as argument
#define ASEQ_OP_CHAN_DYNLDLAYER     0x98 // lower 3 bits used as argument
#define ASEQ_OP_CHAN_LDFILTER       0xB0
#define ASEQ_OP_CHAN_FREEFILTER     0xB1
#define ASEQ_OP_CHAN_LDSEQTOPTR     0xB2
#define ASEQ_OP_CHAN_FILTER         0xB3
#define ASEQ_OP_CHAN_PTRTODYNTBL    0xB4
#define ASEQ_OP_CHAN_DYNTBLTOPTR    0xB5
#define ASEQ_OP_CHAN_DYNTBLV        0xB6
#define ASEQ_OP_CHAN_RANDTOPTR      0xB7
#define ASEQ_OP_CHAN_RAND           0xB8
#define ASEQ_OP_CHAN_RANDVEL        0xB9
#define ASEQ_OP_CHAN_RANDGATE       0xBA
#define ASEQ_OP_CHAN_COMBFILTER     0xBB
#define ASEQ_OP_CHAN_PTRADD         0xBC
#define ASEQ_OP_CHAN_SAMPLESTART    0xBD
#define ASEQ_OP_CHAN_INSTR          0xC1
#define ASEQ_OP_CHAN_DYNTBL         0xC2
#define ASEQ_OP_CHAN_SHORT          0xC3
#define ASEQ_OP_CHAN_NOSHORT        0xC4
#define ASEQ_OP_CHAN_DYNTBLLOOKUP   0xC5
#define ASEQ_OP_CHAN_FONT           0xC6
#define ASEQ_OP_CHAN_STSEQ          0xC7
#define ASEQ_OP_CHAN_SUB            0xC8
#define ASEQ_OP_CHAN_AND            0xC9
#define ASEQ_OP_CHAN_MUTEBHV        0xCA
#define ASEQ_OP_CHAN_LDSEQ          0xCB
#define ASEQ_OP_CHAN_LDI            0xCC
#define ASEQ_OP_CHAN_STOPCHAN       0xCD
#define ASEQ_OP_CHAN_LDPTR          0xCE
#define ASEQ_OP_CHAN_STPTRTOSEQ     0xCF
#define ASEQ_OP_CHAN_EFFECTS        0xD0
#define ASEQ_OP_CHAN_NOTEALLOC      0xD1
#define ASEQ_OP_CHAN_SUSTAIN        0xD2
#define ASEQ_OP_CHAN_BEND           0xD3
#define ASEQ_OP_CHAN_REVERB         0xD4
#define ASEQ_OP_CHAN_VIBFREQ        0xD7
#define ASEQ_OP_CHAN_VIBDEPTH       0xD8
#define ASEQ_OP_CHAN_RELEASERATE    0xD9
#define ASEQ_OP_CHAN_ENV            0xDA
#define ASEQ_OP_CHAN_TRANSPOSE      0xDB
#define ASEQ_OP_CHAN_PANWEIGHT      0xDC
#define ASEQ_OP_CHAN_PAN            0xDD
#define ASEQ_OP_CHAN_FREQSCALE      0xDE
#define ASEQ_OP_CHAN_VOL            0xDF
#define ASEQ_OP_CHAN_VOLEXP         0xE0
#define ASEQ_OP_CHAN_VIBFREQGRAD    0xE1
#define ASEQ_OP_CHAN_VIBDEPTHGRAD   0xE2
#define ASEQ_OP_CHAN_VIBDELAY       0xE3
#define ASEQ_OP_CHAN_DYNCALL        0xE4
#define ASEQ_OP_CHAN_REVERBIDX      0xE5
#define ASEQ_OP_CHAN_SAMPLEBOOK     0xE6
#define ASEQ_OP_CHAN_LDPARAMS       0xE7
#define ASEQ_OP_CHAN_PARAMS         0xE8
#define ASEQ_OP_CHAN_NOTEPRI        0xE9
#define ASEQ_OP_CHAN_STOP           0xEA
#define ASEQ_OP_CHAN_FONTINSTR      0xEB
#define ASEQ_OP_CHAN_VIBRESET       0xEC
#define ASEQ_OP_CHAN_GAIN           0xED
#define ASEQ_OP_CHAN_BENDFINE       0xEE
#define ASEQ_OP_CHAN_EF             0xEF
#define ASEQ_OP_CHAN_FREENOTELIST   0xF0
#define ASEQ_OP_CHAN_ALLOCNOTELIST  0xF1

// layer commands
#define ASEQ_OP_LAYER_NOTEDVG       0x00
#define ASEQ_OP_LAYER_NOTEDV        0x40
#define ASEQ_OP_LAYER_NOTEVG        0x80
#define ASEQ_OP_LAYER_LDELAY        0xC0
#define ASEQ_OP_LAYER_SHORTVEL      0xC1
#define ASEQ_OP_LAYER_TRANSPOSE     0xC2
#define ASEQ_OP_LAYER_SHORTDELAY    0xC3
#define ASEQ_OP_LAYER_LEGATO        0xC4
#define ASEQ_OP_LAYER_NOLEGATO      0xC5
#define ASEQ_OP_LAYER_INSTR         0xC6
#define ASEQ_OP_LAYER_PORTAMENTO    0xC7
#define ASEQ_OP_LAYER_NOPORTAMENTO  0xC8
#define ASEQ_OP_LAYER_SHORTGATE     0xC9
#define ASEQ_OP_LAYER_NOTEPAN       0xCA
#define ASEQ_OP_LAYER_ENV           0xCB
#define ASEQ_OP_LAYER_NODRUMPAN     0xCC
#define ASEQ_OP_LAYER_STEREO        0xCD
#define ASEQ_OP_LAYER_BENDFINE      0xCE
#define ASEQ_OP_LAYER_RELEASERATE   0xCF
#define ASEQ_OP_LAYER_LDSHORTVEL    0xD0 // low nibble used as an argument
#define ASEQ_OP_LAYER_LDSHORTGATE   0xE0 // low nibble used as an argument

#define PITCH_A0       0
#define PITCH_BF0      1
#define PITCH_B0       2
#define PITCH_C1       3
#define PITCH_DF1      4
#define PITCH_D1       5
#define PITCH_EF1      6
#define PITCH_E1       7
#define PITCH_F1       8
#define PITCH_GF1      9
#define PITCH_G1       10
#define PITCH_AF1      11
#define PITCH_A1       12
#define PITCH_BF1      13
#define PITCH_B1       14
#define PITCH_C2       15
#define PITCH_DF2      16
#define PITCH_D2       17
#define PITCH_EF2      18
#define PITCH_E2       19
#define PITCH_F2       20
#define PITCH_GF2      21
#define PITCH_G2       22
#define PITCH_AF2      23
#define PITCH_A2       24
#define PITCH_BF2      25
#define PITCH_B2       26
#define PITCH_C3       27
#define PITCH_DF3      28
#define PITCH_D3       29
#define PITCH_EF3      30
#define PITCH_E3       31
#define PITCH_F3       32
#define PITCH_GF3      33
#define PITCH_G3       34
#define PITCH_AF3      35
#define PITCH_A3       36
#define PITCH_BF3      37
#define PITCH_B3       38
#define PITCH_C4       39
#define PITCH_DF4      40
#define PITCH_D4       41
#define PITCH_EF4      42
#define PITCH_E4       43
#define PITCH_F4       44
#define PITCH_GF4      45
#define PITCH_G4       46
#define PITCH_AF4      47
#define PITCH_A4       48
#define PITCH_BF4      49
#define PITCH_B4       50
#define PITCH_C5       51
#define PITCH_DF5      52
#define PITCH_D5       53
#define PITCH_EF5      54
#define PITCH_E5       55
#define PITCH_F5       56
#define PITCH_GF5      57
#define PITCH_G5       58
#define PITCH_AF5      59
#define PITCH_A5       60
#define PITCH_BF5      61
#define PITCH_B5       62
#define PITCH_C6       63
#define PITCH_DF6      64
#define PITCH_D6       65
#define PITCH_EF6      66
#define PITCH_E6       67
#define PITCH_F6       68
#define PITCH_GF6      69
#define PITCH_G6       70
#define PITCH_AF6      71
#define PITCH_A6       72
#define PITCH_BF6      73
#define PITCH_B6       74
#define PITCH_C7       75
#define PITCH_DF7      76
#define PITCH_D7       77
#define PITCH_EF7      78
#define PITCH_E7       79
#define PITCH_F7       80
#define PITCH_GF7      81
#define PITCH_G7       82
#define PITCH_AF7      83
#define PITCH_A7       84
#define PITCH_BF7      85
#define PITCH_B7       86
#define PITCH_C8       87
#define PITCH_DF8      88
#define PITCH_D8       89
#define PITCH_EF8      90
#define PITCH_E8       91
#define PITCH_F8       92
#define PITCH_GF8      93
#define PITCH_G8       94
#define PITCH_AF8      95
#define PITCH_A8       96
#define PITCH_BF8      97
#define PITCH_B8       98
#define PITCH_C9       99
#define PITCH_DF9      100
#define PITCH_D9       101
#define PITCH_EF9      102
#define PITCH_E9       103
#define PITCH_F9       104
#define PITCH_GF9      105
#define PITCH_G9       106
#define PITCH_AF9      107
#define PITCH_A9       108
#define PITCH_BF9      109
#define PITCH_B9       110
#define PITCH_C10      111
#define PITCH_DF10     112
#define PITCH_D10      113
#define PITCH_EF10     114
#define PITCH_E10      115
#define PITCH_F10      116
#define PITCH_BFNEG1   117
#define PITCH_BNEG1    118
#define PITCH_C0       119
#define PITCH_DF0      120
#define PITCH_D0       121
#define PITCH_EF0      122
#define PITCH_E0       123
#define PITCH_F0       124
#define PITCH_GF0      125
#define PITCH_G0       126
#define PITCH_AF0      127

#define S16(x) (x >> 8), (x & 0xFF)
#define CS16(x) ((x >> 8) | 0x80), (x & 0xFF)

#endif // ASEQ_H
