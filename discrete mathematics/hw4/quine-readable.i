DO ;2 <- #255
DO ;2SUB#1 <- #23948$#3181
DO ;2SUB#2 <- #2568$#53882
DO ;2SUB#3 <- #8776$#4650
DO ;2SUB#4 <- #1260$#40490
DO ;2SUB#5 <- #27757$#26128
DO ;2SUB#6 <- #54082$#1258
DO ;2SUB#7 <- #32099$#811
DO ;2SUB#8 <- #50248$#40237
DO ;2SUB#9 <- #552$#55962
DO ;2SUB#10 <- #56582$#850
DO ;2SUB#11 <- #29560$#2282
DO ;2SUB#12 <- #3805$#21001
DO ;2SUB#13 <- #37509$#7485
DO ;2SUB#14 <- #9070$#6039
DO ;2SUB#15 <- #2723$#25131
DO ;2SUB#16 <- #57608$#6137
DO ;2SUB#17 <- #418$#15338
DO ;2SUB#18 <- #41351$#6397
DO ;2SUB#19 <- #2955$#14435
DO ;2SUB#20 <- #97$#13913
DO ;2SUB#21 <- #551$#23120
DO ;2SUB#22 <- #19065$#58047
DO ;2SUB#23 <- #60707$#12331
DO ;2SUB#24 <- #8718$#59963
DO ;2SUB#25 <- #2727$#27177
DO ;2SUB#26 <- #32830$#14335
DO ;2SUB#27 <- #21192$#6813
DO ;2SUB#28 <- #18998$#59933
DO ;2SUB#29 <- #18386$#40665
DO ;2SUB#30 <- #10400$#42282
DO ;2SUB#31 <- #49759$#63089
DO ;2SUB#32 <- #51502$#38329
DO ;2SUB#33 <- #2568$#21154
DO ;2SUB#34 <- #48931$#32803
DO ;2SUB#35 <- #52561$#12495
DO ;2SUB#36 <- #60975$#8931
DO ;2SUB#37 <- #8953$#14941
DO ;2SUB#38 <- #11269$#62899
DO ;2SUB#39 <- #17007$#27305
DO ;2SUB#40 <- #2883$#40763
DO ;2SUB#41 <- #923$#38920
DO ;2SUB#42 <- #13762$#1181
DO ;2SUB#43 <- #26919$#13475
DO ;2SUB#44 <- #32110$#32805
DO ;2SUB#45 <- #28197$#41531
DO ;2SUB#46 <- #11397$#10933
DO ;2SUB#47 <- #18954$#64311
DO ;2SUB#48 <- #14979$#4735
DO ;2SUB#49 <- #56758$#50331
DO ;2SUB#50 <- #26785$#9765
DO ;2SUB#51 <- #51412$#43774
DO ;2SUB#52 <- #36740$#9147
DO ;2SUB#53 <- #51101$#41909
DO ;2SUB#54 <- #43553$#13603
DO ;2SUB#55 <- #18585$#22919
DO ;2SUB#56 <- #83$#63368
DO ;2SUB#57 <- #16557$#22417
DO ;2SUB#58 <- #8586$#29786
DO ;2SUB#59 <- #16598$#38839
DO ;2SUB#60 <- #849$#55195
DO ;2SUB#61 <- #49734$#31353
DO ;2SUB#62 <- #708$#27299
DO ;2SUB#63 <- #41475$#56753
DO ;2SUB#64 <- #10232$#12153
DO ;2SUB#65 <- #29478$#4389
DO ;2SUB#66 <- #51348$#5783
DO ;2SUB#67 <- #6226$#38397
DO ;2SUB#68 <- #6779$#53847
DO ;2SUB#69 <- #58337$#9053
DO ;2SUB#70 <- #59323$#9495
DO ;2SUB#71 <- #5868$#22011
DO ;2SUB#72 <- #20324$#58283
DO ;2SUB#73 <- #7818$#15727
DO ;2SUB#74 <- #23283$#4831
DO ;2SUB#75 <- #38054$#6651
DO ;2SUB#76 <- #50574$#45010
DO ;2SUB#77 <- #8951$#9943
DO ;2SUB#78 <- #34349$#7969
DO ;2SUB#79 <- #34468$#7641
DO ;2SUB#80 <- #57018$#7647
DO ;2SUB#81 <- #18727$#9134
DO ;2SUB#82 <- #13091$#22815
DO ;2SUB#83 <- #17162$#14185
DO ;2SUB#84 <- #8821$#12919
DO ;2SUB#85 <- #51865$#6553
DO ;2SUB#86 <- #62719$#7099
DO ;2SUB#87 <- #36046$#27566
DO ;2SUB#88 <- #39538$#13037
DO ;2SUB#89 <- #13096$#37807
DO ;2SUB#90 <- #24876$#43309
DO ;2SUB#91 <- #9788$#13051
DO ;2SUB#92 <- #9794$#55763
DO ;2SUB#93 <- #41918$#44978
DO ;2SUB#94 <- #19860$#5917
DO ;2SUB#95 <- #9124$#7133
DO ;2SUB#96 <- #17315$#5037
DO ;2SUB#97 <- #16043$#56731
DO ;2SUB#98 <- #26371$#8565
DO ;2SUB#99 <- #57178$#30514
DO ;2SUB#100 <- #1142$#32061
DO ;2SUB#101 <- #43279$#12336
DO ;2SUB#102 <- #31466$#2002
DO ;2SUB#103 <- #5606$#14719
DO ;2SUB#104 <- #46820$#8021
DO ;2SUB#105 <- #14955$#6781
DO ;2SUB#106 <- #3484$#38981
DO ;2SUB#107 <- #62208$#0

PLEASE .1 <- #255
PLEASE .2 <- .1
DO,2 <- #1
PLEASE.4 <- #0
DO (14) NEXT
PLEASE COME FROM (3)
DO (1020) NEXT
DO STASH .1
PLEASE .2 <- #155
DO :2 <- ;2SUB.1
DO (14) NEXT
PLEASE .2 <- #11
PLEASE .1 <- :2~'#65535$#0'
DO (14) NEXT
PLEASE .2 <- #15
PLEASE .1 <- :2~'#0$#65535'
DO (14) NEXT
PLEASE RETRIEVE .1
PLEASE .5 <- .2~#6
(3) DO (4) NEXT
(2) PLEASE.5 <- #1$!2~#1'
DO (20) NEXT
DO STASH :2
PLEASE .5 <- #1$!2~#2'
DO :2 <- ;2SUB!2~#508'
DO (21) NEXT
PLEASE .2 <- :2~#65280
DO (2) NEXT
PLEASE .2 <- :2~#255
PLEASE RETRIEVE :2
DO (2) NEXT
(20) DO (4) NEXT
PLEASE .5 <- #1$"!2~.2'~#1"
DO (10) NEXT
DO (24) NEXT
(4) DO (1001) NEXT
PLEASE .1 <- #255
PLEASE COME FROM (34)
DO (1020) NEXT
DO (1020) NEXT
PLEASE .2 <- .1(34)
DO (2) NEXT
(14) DO (2) NEXT
(1) PLEASE .5 <- '?"!1~.1'~#1"$#2'~#6
PLEASE .2 <- #10
DO (4) NEXT
DO (1040) NEXT
PLEASE .5 <- .1
PLEASE .1 <- .3
DO (1030) NEXT
DO STASH.1
PLEASE .1 <- .5
PLEASE .2 <- .3
DO (1010) NEXT
PLEASE RETRIEVE .1
DO STASH .3
DO (1) NEXT
PLEASE RETRIEVE .3
PLEASE .2 <- .3$#3
PLEASE .2 <- !2~#15'$!2~#240'
PLEASE .2 <- !2~#15'$!2~#240'
(24) DO STASH .1
PLEASE .1 <- .4
PLEASE .4 <- .2
DO (1010) NEXT
PLEASE RETRIEVE .1
DO ,2 SUB#1 <- .3~#255
PLEASE READOUT ,2
(21) DO (4) NEXT
DO :2 <- :2~'#65280$#65280'
PLEASE .5 <- #3
(10) DO (4) NEXT
PLEASE GIVE UP