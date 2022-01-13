# Online Grading System

-----

>  Team: 
>
>  [@Hongbo Wang ](https://github.com/BOBWang1117) 
>
>  @Yichu Li

>  

## **Environment:**

- System: Linux Ubuntu 

- Language: C++

- Compiler: GNU g++

  

## **Details**:

- Type: term project

- Teacher: 罗少龙

- Computer Language: MySQL, ASP.NET

- Project Name: Online Grading System

- Time: 2020/1/3

- Description: This scheduler can complement a scheduler with four scheduling policy, First-In First-Out, Round Robin, Shortest Job First and preemptive SJF respectively.

  

## **Dependencies:** 

- Chrome



## **Install package:**

- None



## **Run program:**

- add ASP.NET code into Visual Studio
- add SQL code into SQL Server Management Studi



## How to Run:

### Compile

Open Terminal in Linux system(recommended system is Linux Ubuntu), enter:

```
$ g++ -o monitor monitor.cpp
$ make
```

or:

```
$ g++ -o monitor monitor.cpp
$ g++ -o scheduler scheduler.cpp iotxt.cpp
```

### Run

You can write your own file as the format:

| Arrival Time 1 | \t   | Command 1 | \t   | Duration 1 | \n   |
| -------------- | ---- | --------- | ---- | ---------- | ---- |
| Arrival Time 2 | \t   | Command 2 | \t   | Duration 2 | \n   |
| Arrival Time 3 | \t   | Command 3 | \t   | Duration 3 | \n   |

Then, put the file to the same path as the other compiled executable file.

Enter this command in the Terminal (scheduler policy you can choose "FIFO", "RR", "SJF" or "PSJF"):

```
$ ./scheduler [Job Description File Name] [Scheduler Policy]
```
