# Test
Provide source code for each test in this document. Please choose your favorite OS, IDE and
compiler. When sending the code please mention the OS, IDE and compiler that was chosen.
## Test 1
The boot code is represented as a text file with one instruction per line of text. Each instruction consists of an operation (acc, jmp, or nop) and an argument (a signed number like +4 or -20). <br><br>
**acc** increases or decreases a single global value called the **accumulator** by the value given in the argument. For example, acc +7 would increase the accumulator by 7. The accumulator
starts at 0. After an acc instruction, the instruction immediately below it is executed next.
 <br><br>
**jmp** jumps to a new instruction relative to itself. The next instruction to execute is found using the argument as an offset from the jmp instruction; for example, jmp +2 would skip the next
instruction, jmp +1 would continue to the instruction immediately below it, and jmp -20 would
cause the instruction 20 lines above to be executed next.
<br><br>
**nop** stands for No OPeration - it does nothing. The instruction immediately below it is executed next. 
<br><br>
For example, consider the following program:
>nop +0 <br>
>acc +1 <br>
>jmp +4 <br>
acc +3 <br>
jmp -3 <br>
acc -99 <br>
acc +1 <br>
jmp -4 <br>
acc +6 <br>

These instructions are visited in this order:
>1. nop +0 | 1 <br>
>2. acc +1 | 2, 8(!) <br>
>3. jmp +4 | 3 <br>
>4. acc +3 | 6 <br>
>5. jmp -3 | 7 <br>
>6. acc -99 | <br>
>7. acc +1 | 4 <br>
> <br>
>8. jmp -4 | 5 <br>
>9. acc +6 | <br>
<br>

First, the nop +0 does nothing. Then, the accumulator is increased from 0 to 1 (acc +1) and jmp
+4 sets the next instruction to the other acc +1 near the bottom.
 <br> <br>
After it increases the
accumulator from 1 to 2, jmp -4 executes, setting the next instruction to the only acc +3. It sets
the accumulator to 5, and jmp -3 causes the program to continue back at the first acc +1.
 <br><br>
This is an **infinite loop**: with this sequence of jumps, the program will run forever. The moment the program tries to run any instruction a second time, you know it will never terminate.
 <br> <br>
Immediately **before** the program would run an instruction a second time, the value in the
accumulator is **5**.
 <br> <br>
Run your copy of the boot code. 

**Immediately before any instruction is executed a second time,
what value is in the accumulator?**

## Test 2
The automatic passport scanners are slow because they're having trouble detecting which
passports have all required fields. The expected fields are as follows:
- byr (Birth Year)
- iyr (Issue Year)
- eyr (Expiration Year)
- hgt (Height)
- hcl (Hair Color)
- ecl (Eye Color)
- pid (Passport ID)
- cid (Country ID)

Passport data is validated in batch files (your puzzle input). Each passport is represented as a
sequence of key:value pairs separated by spaces or newlines. Passports are separated by
blank lines.
Here is an example batch file containing four passports: <br>
>ecl:gry pid:860033327 eyr:2020 hcl:#fffffd
>byr:1937 iyr:2017 cid:147 hgt:183cm <br>
><br>
>iyr:2013 ecl:amb cid:350 eyr:2023 pid:028048884
>hcl:#cfa07d byr:1929 <br>
><br>
>hcl:#ae17e1 iyr:2013
>eyr:2024
>ecl:brn pid:760753108 byr:1931
>hgt:179cm <br>
><br>
>hcl:#cfa07d eyr:2025 pid:166559648
>iyr:2011 ecl:brn hgt:59in <br>

The first passport is **valid** - all eight fields are present. The second passport is **invalid** - it is
missing hgt (the Height field). <br><br>
The third passport is interesting; **the only missing field is cid**, so it looks like data from North
Pole Credentials, not a passport at all! Surely, nobody would mind if you made the system
temporarily ignore missing cid fields. Treat this "passport" as **valid**. <br><br>
The fourth passport is missing two fields, cid and byr. **Missing cid is fine, but missing any other field is not, so this passport is invalid**.
According to the above rules, your improved system would report 2 valid passports. <br><br>
Count the number of valid passports - those that have all required fields. Treat cid as optional. In
your batch file, how many passports are valid? <br><br>
Prepare two solutions, one should be **single threaded** and the second **multithreaded**. Test it on a
multicore machine and measure execution time difference.