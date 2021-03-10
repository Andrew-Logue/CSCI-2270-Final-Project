%Andrew Logue - Vicky Lopez 4/28/2020
%reads csv file(s) and creates graph
%for CSCI 2270 Final Project
clear
clc
close all

%read csv file data
TimeData = readtable("TimeData_LL.csv");
LL_m = TimeData{:,:};
TimeData = readtable("TimeData_BST.csv");
BST_m = TimeData{:,:};
TimeData = readtable("TimeData_HTChaining.csv");
HTC_m = TimeData{:,:};
TimeData = readtable("TimeData_HTLinear.csv");
HTL_m = TimeData{:,:};
TimeData = readtable("TimeData_HTQuadratic.csv");
HTQ_m = TimeData{:,:};
TimeData = readtable("TimeData_HTDH.csv");
HTDH_m = TimeData{:,:};
DataPoints = readtable("allData.csv");
ALL = DataPoints{:,:};
ALL = ALL';


%begin graphing individual graphs
%Linked List
figure
hold on
plot(LL_m);
%insert grid
grid
%label
xlabel('Iteration')
ylabel('Time (Microseconds)')
title('Execution Times of Insertion and Search in a Linked List')
legend('Insertion', 'Search')
hold off

%BST
figure
hold on
plot(BST_m);
%insert grid
grid
%label
xlabel('Iteration')
ylabel('Time (Microseconds)')
title('Execution Times of Insertion and Search in a Binary Search Tree')
legend('Insertion', 'Search')
hold off

%HT with chaining
figure
hold on
plot(HTC_m);
%insert grid
grid
%label
xlabel('Iteration')
ylabel('Time (Microseconds)')
title('Execution Times of Insertion and Search in a Hash Table using chaining')
legend('Insertion', 'Search')
hold off

%HT with linear probing
figure
hold on
plot(HTL_m);
%insert grid
grid
%label
xlabel('Iteration')
ylabel('Time (Microseconds)')
title('Execution Times of Insertion and Search in a Hash Table using linear probing')
legend('Insertion', 'Search')
hold off

%HT with quadratic probing
figure
hold on
plot(HTQ_m);
%insert grid
grid
%label
xlabel('Iteration')
ylabel('Time (Microseconds)')
title('Execution Times of Insertion and Search in a Hash Table using quadratic probing')
legend('Insertion', 'Search')
hold off

%compare HT with double hashing and HT with quadratic probing
figure
hold on
plot(HTDH_m);
plot(HTQ_m);
%insert grid
grid
%label
xlabel('Iteration')
ylabel('Time (Microseconds)')
title('Execution Times of Insertion and Search in a Hash Table Double Hashing vs. Quadratic Probing (DATA SET A)')
legend('Double Hashing Insertion', 'Double Hashing Search',...
        'Quadratic Probing Insertion', 'Quadratic Probing Search')
hold off

%graph final collective both insertiona and search
figure
hold on
plot(LL_m);
plot(BST_m);
plot(HTC_m);
plot(HTL_m);
plot(HTQ_m);
%insert grid
grid
%label
xlabel('Iteration')
ylabel('Time (Microseconds)')
title('Execution Times of Insertion and Search for each Data Structure')
legend('Linked List Insertion', 'Linked List Search', 'BST Insertion', 'BST Search',... 
        'HT w/ Chaining Insertion', 'HT w/ Chaining Search', 'HT w/ Linear Probing Insertion',...
        'HT w/ Linear Probing Search', 'HT w/ Quadratic Probing Insertion',...
        'HT w/ Qaudratic Probing Search')
hold off

%graph final collective insertion
figure
hold on
plot(LL_m(:,1));
plot(BST_m(:,1));
plot(HTQ_m(:,1));
%insert grid
grid
%label
xlabel('Iteration')
ylabel('Time (Microseconds)')
title('Execution Times of Insertion for each Data Structure')
legend('Linked List Insertion', 'BST Insertion', 'HT w/ Qaudratic Probing Insertion')
hold off

%graph final collective search
figure
hold on
plot(LL_m(:,2));
plot(BST_m(:,2));
plot(HTQ_m(:,2));
%insert grid
grid
%label
xlabel('Iteration')
ylabel('Time (Microseconds)')
title('Execution Times of Search for each Data Structure')
legend('Linked List Search', 'BST Search', 'HT w/ Quadratic Probing Search')
hold off

%graph all given data
figure
hold on
plot(ALL(:,:));
%insert grid
grid
%label
xlabel('Index')
ylabel('Value')
title('Given Data')
legend('Data Set A', 'Data Set B')
hold off

%program end
