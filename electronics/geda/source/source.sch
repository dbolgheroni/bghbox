v 20091004 2
C 42100 49900 1 90 0 resistor-1.sym
{
T 41700 50200 5 10 0 0 90 0 1
device=RESISTOR
T 41800 50000 5 10 1 1 90 0 1
refdes=R102
T 42100 49900 5 10 0 0 0 0 1
footprint=R025
T 42200 50300 5 10 1 1 0 0 1
value=240
}
C 36800 50800 1 270 0 capacitor-2.sym
{
T 37500 50600 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 37300 50600 5 10 1 1 270 0 1
refdes=C101
T 37700 50600 5 10 0 0 270 0 1
symversion=0.1
T 36450 50450 5 10 1 1 0 0 1
value=3300u
T 36800 50800 5 10 0 0 0 0 1
footprint=RCY300P
}
C 41800 49300 1 270 0 capacitor-2.sym
{
T 42500 49100 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 41800 48700 5 10 1 1 270 0 1
refdes=C104
T 42700 49100 5 10 0 0 270 0 1
symversion=0.1
T 41650 48950 5 10 1 1 0 0 1
value=10u
T 41800 49300 5 10 0 0 0 0 1
footprint=RCY100P
}
C 39500 50200 1 0 0 lm317-1.sym
{
T 39800 51900 5 10 0 0 0 0 1
device=LM317
T 41200 51600 5 10 1 1 0 6 1
refdes=U102
T 39500 50200 5 10 0 0 0 0 1
footprint=TO92
}
N 37000 46100 37000 49900 4
C 43800 50800 1 270 0 capacitor-2.sym
{
T 44500 50600 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 44300 50600 5 10 1 1 270 0 1
refdes=C103
T 44700 50600 5 10 0 0 270 0 1
symversion=0.1
T 43600 50500 5 10 1 1 0 0 1
value=1u
T 43800 50800 5 10 0 0 0 0 1
footprint=RCY100P
T 43800 50800 5 10 1 1 0 0 1
comment=solid tantalum
}
N 42000 49300 42000 49900 4
C 42800 50800 1 270 0 diode-3.sym
{
T 43350 50350 5 10 0 0 270 0 1
device=DIODE
T 43250 50450 5 10 1 1 270 0 1
refdes=D101
T 42800 50800 5 10 0 0 90 0 1
footprint=DIODE_LAY 500
}
N 40500 49300 40500 50200 4
N 43000 49500 43000 49900 4
N 42000 51000 42000 50800 4
N 43000 51000 43000 50800 4
N 44000 51000 44000 50800 4
N 44000 46100 44000 49900 4
C 37800 49700 1 270 0 led-1.sym
{
T 38400 48900 5 10 0 0 270 0 1
device=LED
T 37600 49600 5 10 1 1 270 0 1
refdes=LED101
T 38600 48900 5 10 0 0 270 0 1
symversion=0.1
T 37800 49700 5 10 0 0 0 0 1
footprint=LED5
}
C 38100 49900 1 90 0 resistor-1.sym
{
T 37700 50200 5 10 0 0 90 0 1
device=RESISTOR
T 37800 50100 5 10 1 1 90 0 1
refdes=R103
T 38100 49900 5 10 0 0 0 0 1
footprint=R025
T 38100 49900 5 10 1 1 0 0 1
value=6.8k
}
N 38000 50800 38000 51200 4
N 38000 49900 38000 49700 4
N 38000 48800 38000 48000 4
C 40600 48400 1 90 0 resistor-variable-1.sym
{
T 39700 49200 5 10 0 0 90 0 1
device=VARIABLE_RESISTOR
T 40200 49000 5 10 1 1 90 0 1
refdes=R101
T 40600 48400 5 10 1 1 0 0 1
value=5k
}
N 41500 51000 44500 51000 4
C 48000 48100 1 180 0 nc-left-1.sym
{
T 48000 47700 5 10 0 0 180 0 1
value=NoConnection
T 48000 47300 5 10 0 0 180 0 1
device=DRC_Directive
}
N 47500 48000 44000 48000 4
C 40600 47600 1 90 1 resistor-variable-1.sym
{
T 39700 46800 5 10 0 0 270 2 1
device=VARIABLE_RESISTOR
T 40200 47000 5 10 1 1 270 2 1
refdes=R201
T 40600 47600 5 10 1 1 0 0 1
value=5k
}
C 41800 47600 1 270 0 capacitor-2.sym
{
T 42500 47400 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 42400 47400 5 10 1 1 270 0 1
refdes=C204
T 42700 47400 5 10 0 0 270 0 1
symversion=0.1
T 41650 47250 5 10 1 1 0 0 1
value=10u
T 41800 47600 5 10 0 0 0 0 1
footprint=RCY100P
}
C 36800 46100 1 270 0 capacitor-2.sym
{
T 37500 45900 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 37300 45900 5 10 1 1 270 0 1
refdes=C201
T 37700 45900 5 10 0 0 270 0 1
symversion=0.1
T 36450 45750 5 10 1 1 0 0 1
value=3300u
T 36800 46100 5 10 0 0 0 0 1
footprint=RCY300P
}
C 41900 46100 1 270 0 resistor-1.sym
{
T 42300 45800 5 10 0 0 270 0 1
device=RESISTOR
T 42200 45900 5 10 1 1 270 0 1
refdes=R202
T 41900 46100 5 10 0 0 180 0 1
footprint=R025
T 41800 45700 5 10 1 1 180 0 1
value=240
}
C 43200 45200 1 90 0 diode-3.sym
{
T 42650 45650 5 10 0 0 90 0 1
device=DIODE
T 42750 45550 5 10 1 1 90 0 1
refdes=D201
T 43200 45200 5 10 0 0 270 0 1
footprint=DIODE_LAY 500
}
C 43800 46100 1 270 0 capacitor-2.sym
{
T 44500 45900 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 44300 45900 5 10 1 1 270 0 1
refdes=C203
T 44700 45900 5 10 0 0 270 0 1
symversion=0.1
T 43600 45800 5 10 1 1 0 0 1
value=1u
T 43800 46100 5 10 0 0 0 0 1
footprint=RCY100P
T 43800 46100 5 10 1 1 0 0 1
comment=solid tantalum
}
C 31500 51900 1 0 0 nc-left-1.sym
{
T 31500 52300 5 10 0 0 0 0 1
value=NoConnection
T 31500 52700 5 10 0 0 0 0 1
device=DRC_Directive
}
C 31500 48900 1 0 0 nc-left-1.sym
{
T 31500 49300 5 10 0 0 0 0 1
value=NoConnection
T 31500 49700 5 10 0 0 0 0 1
device=DRC_Directive
}
N 32500 45000 39500 45000 4
N 39000 45200 39000 45000 4
N 40500 45800 40500 46700 4
N 41500 45000 47500 45000 4
N 43000 45000 43000 45200 4
N 42000 45200 42000 45000 4
N 42000 46100 42000 46700 4
N 43000 46100 43000 46500 4
N 44000 45000 44000 45200 4
C 48000 45100 1 180 0 nc-left-1.sym
{
T 48000 44700 5 10 0 0 180 0 1
value=NoConnection
T 48000 44300 5 10 0 0 180 0 1
device=DRC_Directive
}
C 44500 50800 1 0 0 switch-spdt-1.sym
{
T 44900 51600 5 10 0 0 0 0 1
device=SPDT
T 44700 51300 5 10 1 1 0 0 1
refdes=S101
}
C 45700 50700 1 0 0 resistor-1.sym
{
T 46000 51100 5 10 0 0 0 0 1
device=RESISTOR
T 45900 51000 5 10 1 1 0 0 1
refdes=R104
T 46000 50500 5 10 1 1 0 0 1
value=0.2
T 45700 50700 5 10 0 0 0 0 1
footprint=ACY800
}
N 45400 50800 45700 50800 4
N 45400 51200 46900 51200 4
N 46900 51200 46900 50800 4
N 46900 50800 46600 50800 4
C 48000 51100 1 180 0 nc-left-1.sym
{
T 48000 50700 5 10 0 0 180 0 1
value=NoConnection
T 48000 50300 5 10 0 0 180 0 1
device=DRC_Directive
}
N 47500 51000 46900 51000 4
N 38800 53500 44000 53500 4
N 44000 51000 44000 53500 4
C 38100 51200 1 90 0 resistor-1.sym
{
T 37700 51500 5 10 0 0 90 0 1
device=RESISTOR
T 37800 51400 5 10 1 1 90 0 1
refdes=R105
T 38100 51200 5 10 0 0 0 0 1
footprint=R025
T 38100 51200 5 10 1 1 0 0 1
value=6.8k
}
N 38000 52100 38000 52500 4
N 37000 53500 37200 53500 4
N 37000 48000 44000 48000 4
N 36500 48000 36500 56500 4
N 32000 48000 37000 48000 4
C 32900 47500 1 0 0 gnd-1.sym
N 33000 47800 33000 48000 4
C 39700 54900 1 0 0 lm7805-1.sym
{
T 41300 56200 5 10 0 0 0 0 1
device=7805
T 41000 55900 5 10 1 1 0 6 1
refdes=U302
T 39700 54900 5 10 0 0 0 0 1
footprint=TO220W
}
C 38800 55300 1 270 0 capacitor-1.sym
{
T 39500 55100 5 10 0 0 270 0 1
device=CAPACITOR
T 39300 55100 5 10 1 1 270 0 1
refdes=C301
T 39700 55100 5 10 0 0 270 0 1
symversion=0.1
T 38800 55300 5 10 0 0 0 0 1
comment=0.22uF as National datasheet says, maybe doesn't matter if it's ceramic, poliester or electrolytic capacitor
T 38800 55300 5 10 0 0 0 0 1
footprint=ACY300
T 38500 55000 5 10 1 1 0 0 1
value=0.22u
}
N 37000 55500 39700 55500 4
N 40500 54900 40500 54000 4
C 48000 55600 1 180 0 nc-left-1.sym
{
T 48000 55200 5 10 0 0 180 0 1
value=NoConnection
T 48000 54800 5 10 0 0 180 0 1
device=DRC_Directive
}
N 37000 50800 37000 59500 4
C 39500 58700 1 0 0 lm317-1.sym
{
T 39800 60400 5 10 0 0 0 0 1
device=LM317
T 41200 60100 5 10 1 1 0 6 1
refdes=U402
T 39500 58700 5 10 0 0 0 0 1
footprint=TO220W
}
C 42100 58400 1 90 0 resistor-1.sym
{
T 41700 58700 5 10 0 0 90 0 1
device=RESISTOR
T 41800 58500 5 10 1 1 90 0 1
refdes=R402
T 42100 58400 5 10 0 0 0 0 1
footprint=R025
T 42200 58800 5 10 1 1 0 0 1
value=240
}
C 42800 59300 1 270 0 diode-3.sym
{
T 43350 58850 5 10 0 0 270 0 1
device=DIODE
T 43250 58950 5 10 1 1 270 0 1
refdes=D401
T 42800 59300 5 10 0 0 90 0 1
footprint=DIODE_LAY 500
}
C 43800 59300 1 270 0 capacitor-2.sym
{
T 44500 59100 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 44300 59100 5 10 1 1 270 0 1
refdes=C403
T 44700 59100 5 10 0 0 270 0 1
symversion=0.1
T 43600 59000 5 10 1 1 0 0 1
value=1u
T 43800 59300 5 10 0 0 0 0 1
footprint=RCY100P
T 43800 59300 5 10 1 1 0 0 1
comment=solid tantalum
}
C 41800 57800 1 270 0 capacitor-2.sym
{
T 42500 57600 5 10 0 0 270 0 1
device=POLARIZED_CAPACITOR
T 41800 57200 5 10 1 1 270 0 1
refdes=C404
T 42700 57600 5 10 0 0 270 0 1
symversion=0.1
T 41650 57450 5 10 1 1 0 0 1
value=10u
T 41800 57800 5 10 0 0 0 0 1
footprint=RCY100P
}
C 40600 56900 1 90 0 resistor-variable-1.sym
{
T 39700 57700 5 10 0 0 90 0 1
device=VARIABLE_RESISTOR
T 40200 57500 5 10 1 1 90 0 1
refdes=R401
T 40600 56900 5 10 1 1 0 0 1
value=5k
}
N 39500 59500 37000 59500 4
N 39000 59300 39000 59500 4
N 36500 56500 44000 56500 4
N 39000 56500 39000 58400 4
N 41500 59500 47500 59500 4
N 42000 59500 42000 59300 4
N 43000 59500 43000 59300 4
N 44000 59300 44000 59500 4
N 43000 58400 43000 58000 4
N 42000 57800 42000 58400 4
N 40500 57800 40500 58700 4
N 40500 56900 40500 56500 4
N 44000 56500 44000 58400 4
C 48000 59600 1 180 0 nc-left-1.sym
{
T 48000 59200 5 10 0 0 180 0 1
value=NoConnection
T 48000 58800 5 10 0 0 180 0 1
device=DRC_Directive
}
T 52700 38700 9 10 1 0 0 0 1
1
T 54200 38700 9 10 1 0 0 0 1
1
T 56600 38700 9 10 1 0 0 0 1
DANIEL BOLGHERONI
N 39000 54000 39000 54400 4
N 42000 54000 42000 54400 4
N 42000 54000 36500 54000 4
N 39000 55300 39000 55500 4
N 41300 55500 47500 55500 4
N 42000 55500 42000 55300 4
C 41800 55300 1 270 0 capacitor-1.sym
{
T 42500 55100 5 10 0 0 270 0 1
device=CAPACITOR
T 42300 55100 5 10 1 1 270 0 1
refdes=C302
T 42700 55100 5 10 0 0 270 0 1
symversion=0.1
T 41800 55300 5 10 0 0 0 0 1
comment=0.1uF CERAMIC as National datasheet says
T 41800 55300 5 10 0 0 0 0 1
footprint=ACY300
T 41600 55000 5 10 1 1 0 0 1
value=0.1u
}
N 39000 50800 39000 52300 4
N 39000 49900 39000 48000 4
N 39000 48000 39000 46100 4
N 40500 47600 40500 48000 4
N 40500 48000 40500 48400 4
C 31500 47900 1 0 0 nc-left-1.sym
{
T 31500 48300 5 10 0 0 0 0 1
value=NoConnection
T 31500 48700 5 10 0 0 0 0 1
device=DRC_Directive
}
C 39200 49900 1 90 0 capacitor-1.sym
{
T 38500 50100 5 10 0 0 90 0 1
device=CAPACITOR
T 38700 50100 5 10 1 1 90 0 1
refdes=C102
T 38300 50100 5 10 0 0 90 0 1
symversion=0.1
T 39200 49900 5 10 0 0 0 0 1
footprint=ACY300
T 39100 50100 5 10 1 1 0 0 1
value=0.1u
}
C 39200 45200 1 90 0 capacitor-1.sym
{
T 38500 45400 5 10 0 0 90 0 1
device=CAPACITOR
T 38700 45400 5 10 1 1 90 0 1
refdes=C202
T 38300 45400 5 10 0 0 90 0 1
symversion=0.1
T 39200 45200 5 10 0 0 0 0 1
footprint=ACY300
T 39100 45400 5 10 1 1 0 0 1
value=0.1u
}
C 39200 58400 1 90 0 capacitor-1.sym
{
T 38500 58600 5 10 0 0 90 0 1
device=CAPACITOR
T 38700 58600 5 10 1 1 90 0 1
refdes=C402
T 38300 58600 5 10 0 0 90 0 1
symversion=0.1
T 39200 58400 5 10 0 0 0 0 1
footprint=ACY300
T 39200 58400 5 10 1 1 0 0 1
value=0.1u
}
N 40500 49500 42000 49500 4
N 42000 48400 42000 48000 4
N 42000 47600 42000 48000 4
N 42000 46500 40500 46500 4
N 42000 58000 40500 58000 4
N 42000 58000 43000 58000 4
N 42000 56900 42000 56500 4
N 42000 49500 43000 49500 4
N 42000 46500 43000 46500 4
C 26800 38400 1 0 0 title-bordered-A1.sym
C 40000 52100 1 0 0 diode-3.sym
{
T 40450 52650 5 10 0 0 0 0 1
device=DIODE
T 40350 52550 5 10 1 1 0 0 1
refdes=D102
T 40000 52100 5 10 0 0 180 0 1
footprint=DIODE_LAY 500
}
N 40000 52300 39000 52300 4
N 40900 52300 42000 52300 4
N 42000 52300 42000 51000 4
C 40000 43500 1 0 0 diode-3.sym
{
T 40450 44050 5 10 0 0 0 0 1
device=DIODE
T 40350 43950 5 10 1 1 0 0 1
refdes=D202
T 40000 43500 5 10 0 0 180 0 1
footprint=DIODE_LAY 500
}
N 40000 43700 39000 43700 4
N 40900 43700 42000 43700 4
N 42000 43700 42000 45000 4
C 40000 60300 1 0 0 diode-3.sym
{
T 40450 60850 5 10 0 0 0 0 1
device=DIODE
T 40350 60750 5 10 1 1 0 0 1
refdes=D402
T 40000 60300 5 10 0 0 180 0 1
footprint=DIODE_LAY 500
}
N 40000 60500 39000 60500 4
N 39000 60500 39000 59500 4
N 40900 60500 42000 60500 4
N 42000 60500 42000 59500 4
N 39000 43700 39000 45000 4
N 35400 49800 36000 49800 4
N 37000 51000 38000 51000 4
N 38000 51000 39000 51000 4
N 39000 51000 39500 51000 4
N 34500 49800 34300 49800 4
N 34500 51000 34300 51000 4
N 33000 49800 33000 51000 4
N 33000 49800 33400 49800 4
N 33000 51000 33400 51000 4
N 34400 49000 34400 49800 4
N 32000 52000 34400 52000 4
N 34400 52000 34400 51000 4
N 37000 51000 35400 51000 4
N 33000 50500 32500 50500 4
N 36000 49800 36000 51000 4
N 32500 50500 32500 45000 4
C 35400 51200 1 180 0 diode-3.sym
{
T 34950 50650 5 10 0 0 180 0 1
device=DIODE
T 35050 50750 5 10 1 1 180 0 1
refdes=D1
T 35400 51200 5 10 0 0 0 0 1
footprint=DIODE_LAY 800
}
C 34300 51200 1 180 0 diode-3.sym
{
T 33850 50650 5 10 0 0 180 0 1
device=DIODE
T 33950 50750 5 10 1 1 180 0 1
refdes=D3
T 34300 51200 5 10 0 0 0 0 1
footprint=DIODE_LAY 800
}
C 35400 50000 1 180 0 diode-3.sym
{
T 34950 49450 5 10 0 0 180 0 1
device=DIODE
T 35050 49550 5 10 1 1 180 0 1
refdes=D2
T 35400 50000 5 10 0 0 0 0 1
footprint=DIODE_LAY 800
}
C 34300 50000 1 180 0 diode-3.sym
{
T 33850 49450 5 10 0 0 180 0 1
device=DIODE
T 33950 49550 5 10 1 1 180 0 1
refdes=D4
T 34300 50000 5 10 0 0 0 0 1
footprint=DIODE_LAY 800
}
N 32000 49000 34400 49000 4
N 37000 45200 37000 45000 4
T 56500 39000 9 10 1 0 0 0 1
D
T 52700 39300 9 10 1 0 0 0 1
SOURCE 20110607
C 39500 45800 1 180 1 lm337-1.sym
{
T 39800 44100 5 10 0 0 180 6 1
device=LM337
T 41200 44400 5 10 1 1 180 0 1
refdes=U202
T 39500 45800 5 10 0 0 0 0 1
footprint=TO220W
}
C 37200 52500 1 270 1 darlington-PNP-1.sym
{
T 37300 52900 5 10 1 1 90 2 1
refdes=T101
T 38602 54002 5 10 0 0 90 2 1
device=DARLINGTON
T 37995 53995 5 10 0 0 90 2 1
footprint=TO220
}