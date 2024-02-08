files=[
    "Brackets_in_Harmony.cpp",
    "Frequency_String.cpp",
    "Mystical_Math.cpp",
    "The_Cryptic_Matrix.cpp",
]

for file in files:
    f=open(file,'r').read()
    f.replace(" ",'')
    f.replace("\n",'')
    f.replace("\t",'')
    print(file,":",len(f))

