You got it! I'll ensure the simulated outputs strictly follow the Oracle SQL*Plus style for DDL/DML confirmations, including table/object names where appropriate, and "1 row inserted" for insertions.

Here is the revised simulation with the corrected output messages.

---

**Question 1: Customer Table**  
Create a table customer (cust_no varchar (5), cust_name varchar (15), age number, phone varchar (10))  
a) insert 5 records and display it  
b) add new field d_birth with date datatype  
c) create another table cust_phone with fields cust_name and phone from customer table  
d) remove the field age  
e) change the size of the cust_name to 25  
f) delete all the records from the table  
g) rename the table cutomer to cust  
h) drop the table 

**Table Schema: customer**
(initially)
| Field Name | Data Type    | Constraints |
| :--------- | :----------- | :---------- |
| cust_no    | VARCHAR(5)   |             |
| cust_name  | VARCHAR(15)  |             |
| age        | NUMBER(10)   |             |
| phone      | VARCHAR(10)  |             |

**Simulated Output:**

```sql
create table customer(cust_no varchar(5), cust_name varchar(15), age number(10), phone varchar(10));
```
**Output:**
Table CUSTOMER created.

```sql
desc customer;
```
**Output:**
| Name      | Null? | Type         |
| :-------- | :---- | :----------- |
| CUST_NO   |       | VARCHAR2(5)  |
| CUST_NAME |       | VARCHAR2(15) |
| AGE       |       | NUMBER(10)   |
| PHONE     |       | VARCHAR2(10) |

```sql
-- a) insert 5 records and display it (PDF shows 3 inserts)
insert into customer(cust_no, cust_name, age, phone) values('C001','A',10,'12345');
```
**Output:**
1 row inserted.

```sql
insert into customer(cust_no, cust_name, age, phone) values('C002','B',11,'123456');
```
**Output:**
1 row inserted.

```sql
insert into customer(cust_no, cust_name, age, phone) values('C003','C',12,'1234567');
```
**Output:**
1 row inserted.

```sql
select * from customer;
```
**Output:**
| CUST_NO | CUST_NAME | AGE | PHONE   |
| :------ | :-------- | :-: | :------ |
| C001    | A         | 10  | 12345   |
| C002    | B         | 11  | 123456  |
| C003    | C         | 12  | 1234567 |

```sql
-- b) add new field d_birth with date datatype
alter table customer add d_birth date;
```
**Output:**
Table CUSTOMER altered.

```sql
-- c) create another table cust_phone with fields cust_name and phone from customer table
create table cust_phone as select cust_name,phone from customer;
```
**Output:**
Table CUST_PHONE created.

```sql
select * from cust_phone;
```
**Output:**
| CUST_NAME | PHONE   |
| :-------- | :------ |
| A         | 12345   |
| B         | 123456  |
| C         | 1234567 |

```sql
-- d) remove the field age
alter table customer drop column age;
```
**Output:**
Table CUSTOMER altered.

```sql
select * from customer;
```
**Output:**
| CUST_NO | CUST_NAME | PHONE   | D_BIRTH |
| :------ | :-------- | :------ | :------ |
| C001    | A         | 12345   |         |
| C002    | B         | 123456  |         |
| C003    | C         | 1234567 |         |

```sql
-- e) change the size of the cust_name to 25
alter table customer modify cust_name varchar(25);
```
**Output:**
Table CUSTOMER altered.

```sql
-- f) delete all the records from the table
truncate table customer;
```
**Output:**
Table CUSTOMER truncated.

```sql
-- g) rename the table customer to cust
alter table customer rename to cust;
```
**Output:**
*(Typically no specific "Table renamed" message in SQL*Plus for this exact command; it returns to the prompt. The PDF's output section for 1.g also doesn't show a message.)*

```sql
-- h) drop the table
drop table cust;
```
**Output:**
Table CUST dropped.

---

**Question 2: Sales_man and Sales_order Tables**  
Create a table sales_man ( salesman_no place, phone unique) Create table sales_order(order_no order_date not null salesman_no primary key primary key, s_name not null, foreign key references salesman_no in sales_man del_type values should be either P or F (check constraints) order_status values should be 'Inprocess','Fullfilled','Backorder', 'Cancelled' (check constraints))  
a) Insert few records in both tables  
b) Delete primary key from sales_man table  
c) Delete Foreign key and Check constraints from sales_order table  
d) Add primary key in sales_man using ALTER TABLE  
e) Add foreign key and CHECK constraints in sales_order table using ALTER TABLE  

**Table Schema: sales_man**
| Field Name  | Data Type   | Constraints                    |
| :---------- | :---------- | :----------------------------- |
| salesman_no | VARCHAR(5)  | PRIMARY KEY                    |
| s_name      | VARCHAR(20) | NOT NULL                       |
| place       | VARCHAR(25) |                                |
| phone       | NUMBER(10)  | UNIQUE                         |

**Table Schema: sales_order**
| Field Name   | Data Type   | Constraints                                                                                                |
| :----------- | :---------- | :--------------------------------------------------------------------------------------------------------- |
| order_no     | VARCHAR(5)  | PRIMARY KEY                                                                                                |
| order_date   | DATE        | NOT NULL                                                                                                   |
| salesman_no  | VARCHAR(5)  | REFERENCES sales_man(salesman_no)                                                                          |
| del_type     | VARCHAR(2)  | CHECK(del_type IN ('P','F'))                                                                               |
| order_status | VARCHAR(10) | CHECK(order_status IN ('Inprocess','Fullfilled','Backorder','Cancelled')) |

**Simulated Output:**

```sql
create table sales_man(salesman_no varchar(5) primary key, s_name varchar(20) not null, place varchar(25), phone number(10) unique);
```
**Output:**
Table SALES_MAN created.

```sql
create table sales_order(order_no varchar(5) primary key, order_date date not null, salesman_no varchar(5) references sales_man(salesman_no), del_type varchar(2) check(del_type in ('P','F')), order_status varchar(10) check(order_status in ('Inprocess','Fullfilled','Backorder','Cancelled')));
```
**Output:**
Table SALES_ORDER created.

```sql
-- a) Insert few records in both tables
insert into sales_man(salesman_no,s_name,place,phone) values('S001','A','Calicut',12345);
```
**Output:**
1 row inserted.

```sql
insert into sales_man(salesman_no,s_name,place,phone) values('S002','B','Kozhikode',123456);
```
**Output:**
1 row inserted.

```sql
select * from sales_man;
```
**Output:**
| SALESMAN_NO | S_NAME | PLACE     | PHONE  |
| :---------- | :----- | :-------- | :----- |
| S001        | A      | Calicut   | 12345  |
| S002        | B      | Kozhikode | 123456 |

```sql
insert into sales_order values('O001','19-JAN-2019','S001','P','Inprocess');
```
**Output:**
1 row inserted.

```sql
insert into sales_order values('O002','19-FEB-2019','S002','F','Fullfilled');
```
**Output:**
1 row inserted.

```sql
select * from sales_order;
```
**Output:**
| ORDER_NO | ORDER_DATE | SALESMAN_NO | DEL_TYPE | ORDER_STATUS |
| :------- | :--------- | :---------- | :------- | :----------- |
| O001     | 19-JAN-19  | S001        | P        | Inprocess    |
| O002     | 19-FEB-19  | S002        | F        | Fullfilled   |

```sql
-- b) Delete primary key from sales_man table
alter table sales_man drop primary key;
```
**Output:**
Table SALES_MAN altered.

```sql
-- c) Delete Foreign key and Check constraints from sales_order table
-- Assuming fk_salesman_no is the actual constraint name for the foreign key
ALTER TABLE sales_order DROP CONSTRAINT sales_order_ibfk_1; -- Replace with actual FK name if known
```
**Output:**
Table SALES_ORDER altered.

```sql
-- d) Add primary key in sales_man using ALTER TABLE
ALTER TABLE sales_man ADD PRIMARY KEY (salesman_no);
```
**Output:**
Table SALES_MAN altered.

```sql
-- e) Add foreign key and CHECK constraints in sales_order table using ALTER TABLE
ALTER TABLE sales_order ADD FOREIGN KEY (salesman_no) REFERENCES sales_man(salesman_no);
```
**Output:**
Table SALES_ORDER altered.

---

**Question 3: Hospital Table**  
Create a table Hospital with the fields (doctorid,doctorname,department,qualification,experience).  
a) Insert 5 records  
b) Display the details of Doctors  
c) Display the details of doctors who have the qualification ‘MD’  
d) Display all doctors who have more than 5 years experience but do not have the qualification ‘MD’  
e) Display the doctors in ‘Skin’ department  
f) update the experience of doctor with doctored=’D003’ to 5  
g) Delete the doctor with DoctorID=’D005

**Table Schema: hospital**
| Field Name    | Data Type   | Constraints |
| :------------ | :---------- | :---------- |
| doctor_id     | VARCHAR(5)  |             |
| doctor_name   | VARCHAR(10) |             |
| department    | VARCHAR(15) |             |
| qualification | VARCHAR(15) |             |
| experience    | NUMBER(5)   |             |

**Simulated Output:**

```sql
create table hospital(doctor_id varchar(5), doctor_name varchar(10),department varchar(15), qualification varchar(15), experience number(5));
```
**Output:**
Table HOSPITAL created.

```sql
-- a) Insert 5 records (PDF output shows 6 records)
insert into hospital values('D001','A','skin','MD',1);
```
**Output:**
1 row inserted.
```sql
insert into hospital values('D002','B','skin','MD',5);
```
**Output:**
1 row inserted.
```sql
insert into hospital values('D003','C','ortho','MD',8);
```
**Output:**
1 row inserted.
```sql
insert into hospital values('D005','D','gync','MD',9);
```
**Output:**
1 row inserted.
```sql
insert into hospital values('D006','E','skin','MBBS',1);
```
**Output:**
1 row inserted.
```sql
insert into hospital values('D008','F','skin','MBBS',9);
```
**Output:**
1 row inserted.

```sql
-- b) Display the details of Doctors
select * from hospital;
```
**Output:**
| DOCTOR_ID | DOCTOR_NAME | DEPARTMENT | QUALIFICATION | EXPERIENCE |
| :-------- | :---------- | :--------- | :------------ | :--------- |
| D001      | A           | skin       | MD            | 1          |
| D002      | B           | skin       | MD            | 5          |
| D003      | C           | ortho      | MD            | 8          |
| D005      | D           | gync       | MD            | 9          |
| D006      | E           | skin       | MBBS          | 1          |
| D008      | F           | skin       | MBBS          | 9          |

```sql
-- c) Display the details of doctors who have the qualification ‘MD’
select doctor_name,qualification from hospital where qualification ='MD';
```
**Output:**
| DOCTOR_NAME | QUALIFICATION |
| :---------- | :------------ |
| A           | MD            |
| B           | MD            |
| C           | MD            |
| D           | MD            |

```sql
-- d) Display all doctors who have more than 5 years experience but do not have the qualification 'MD'
select doctor_name,qualification, experience from hospital where experience>5 and qualification!='MD';
```
**Output:**
| DOCTOR_NAME | QUALIFICATION | EXPERIENCE |
| :---------- | :------------ | :--------- |
| F           | MBBS          | 9          |

```sql
-- e) Display the doctors in 'Skin' department
select doctor_name,department from hospital where department='skin';
```
**Output:**
| DOCTOR_NAME | DEPARTMENT |
| :---------- | :--------- |
| A           | skin       |
| B           | skin       |
| E           | skin       |
| F           | skin       |

```sql
-- f) update the experience of doctor with doctor_id='D005' to 5
update hospital set experience =5 where doctor_id='D005';
```
**Output:**
1 row updated.

```sql
-- g) Delete the doctor with DoctorID='D005'
delete from hospital where doctor_id='D005';
```
**Output:**
1 row deleted.

---

**Question 4: Bank Tables**  
Create the following tables:
Bank_customer (accno primary key, cust_name, place) Deposit (accno foreign key, deposit_no, damount) Loan (accno foreign key loan_no, Lamount)  
a) Display the details of the customers  
b) Display the customers along with deposit amount who have only deposit with the bank  
c) Display the customers along with loan amount who have only loan with the bank  
d) Display the customers they have both loan and deposit with the bank  
e) Display the customer who have neither a loan nor a deposit with the bank 

**Table Schema: Bank_customer**
| Field Name | Data Type   | Constraints |
| :--------- | :---------- | :---------- |
| accno      | NUMBER(3)   | PRIMARY KEY |
| cust_name  | VARCHAR(10) |             |
| place      | VARCHAR(20) |             |

**Table Schema: Deposit**
| Field Name | Data Type | Constraints                       |
| :--------- | :-------- | :-------------------------------- |
| accno      | NUMBER(3) | REFERENCES bank_customer(accno) |
| deposit_no | NUMBER(3) |                                   |
| damount    | NUMBER(5) |                                   |

**Table Schema: Loan**
| Field Name | Data Type | Constraints                       |
| :--------- | :-------- | :-------------------------------- |
| accno      | NUMBER(3) | REFERENCES bank_customer(accno) |
| loan_no    | NUMBER(3) |                                   |
| damount    | NUMBER(5) |                                   |

**Simulated Output:**

```sql
create table bank_customer(accno number(3)primary key, cust_name varchar(10), place varchar(20));
```
**Output:**
Table BANK_CUSTOMER created.

```sql
insert into bank_customer(accno, cust_name, place) values(001,'aysha','kollam');
```
**Output:**
1 row inserted.
```sql
insert into bank_customer(accno, cust_name, place) values(002,'anu','koyilandy');
```
**Output:**
1 row inserted.
```sql
insert into bank_customer(accno, cust_name, place) values(003,'manu','calicut');
```
**Output:**
1 row inserted.
```sql
insert into bank_customer(accno, cust_name, place) values(004,'priya','vadakara');
```
**Output:**
1 row inserted.
```sql
insert into bank_customer(accno, cust_name, place) values(005,'fathima','ekm');
```
**Output:**
1 row inserted.

```sql
select * from bank_customer;
```
**Output:**
| ACCNO | CUST_NAME | PLACE     |
| :---- | :-------- | :-------- |
| 1     | aysha     | kollam    |
| 2     | anu       | koyilandy |
| 3     | manu      | calicut   |
| 4     | priya     | vadakara  |
| 5     | fathima   | ekm       |

```sql
create table deposit(accno number(3) references bank_customer(accno), deposit_no number(3),damount number(5));
```
**Output:**
Table DEPOSIT created.

```sql
insert into deposit values(002,02,25000);
```
**Output:**
1 row inserted.
```sql
insert into deposit values(003,103,50000);
```
**Output:**
1 row inserted.```sql
insert into deposit values(004,104,40000);
```
**Output:**
1 row inserted.
```sql
insert into deposit values(005,105,34000);
```
**Output:**
1 row inserted.

```sql
select * from deposit;
```
**Output:**
| ACCNO | DEPOSIT_NO | DAMOUNT |
| :---- | :--------- | :------ |
| 2     | 2          | 25000   |
| 3     | 103        | 50000   |
| 4     | 104        | 40000   |
| 5     | 105        | 34000   |

```sql
create table loan(accno number(3) references bank_customer(accno), loan_no number(3), damount number(5));
```
**Output:**
Table LOAN created.

```sql
insert into loan values(001,1,25000);
```
**Output:**
1 row inserted.
```sql
insert into loan values(002,2,40000);
```
**Output:**
1 row inserted.
```sql
insert into loan values(003,3,50000);
```
**Output:**
1 row inserted.
```sql
insert into loan values(004,4,45000);
```
**Output:**
1 row inserted.
```sql
insert into loan values(005,5,90000);
```
**Output:**
1 row inserted.

```sql
select * from loan;
```
**Output:**
| ACCNO | LOAN_NO | DAMOUNT |
| :---- | :------ | :------ |
| 1     | 1       | 25000   |
| 2     | 2       | 40000   |
| 3     | 3       | 50000   |
| 4     | 4       | 45000   |
| 5     | 5       | 90000   |

```sql
-- a) Display the details of the customers (covered by select * from bank_customer previously)

-- b) Display the customers along with deposit amount who have only deposit with the bank  
select bank_customer.cust_name,deposit.damount from bank_customer inner join deposit on bank_customer.accno=deposit.accno;
```
**Output:**
| CUST_NAME | DAMOUNT |
| :-------- | :------ |
| anu       | 25000   |
| manu      | 50000   |
| priya     | 40000   |
| fathima   | 34000   |

```sql
-- c) Display the customers along with loan amount who have only loan with the bank
select bank_customer.cust_name, loan.damount from bank_customer inner join loan on bank_customer.accno=loan.accno;
```
**Output:**
| CUST_NAME | DAMOUNT |
| :-------- | :------ |
| aysha     | 25000   |
| anu       | 40000   |
| manu      | 50000   |
| priya     | 45000   |
| fathima   | 90000   |

```sql
-- d) Display the customers they have both loan and deposit with the bank
select bank_customer.cust_name from bank_customer inner join deposit on bank_customer.accno=deposit.accno intersect select bank_customer.cust_name from bank_customer inner join loan on bank_customer.accno=loan.accno;
```
**Output:**
| CUST_NAME |
| :-------- |
| anu       |
| manu      |
| priya     |
| fathima   |

```sql
-- e) Display the customer who have neither a loan nor a deposit with the bank
select bank_customer.cust_name from bank_customer inner join deposit on bank_customer.accno=deposit.accno union select bank_customer.cust_name from bank_customer inner join loan on bank_customer.accno=loan.accno;
```
**Output:**
| CUST_NAME |
| :-------- |
| aysha     |
| anu       |
| fathima   |
| manu      |
| priya     |

---

**Question 5: Employee Table**  
Create a table employee with fields (EmpID, EName, Salary, Department, and Age). Insert some records. Write SQL queries using aggregate functions and group by clause  
A. Display the total number of employees.  
B. Display the name and age of the oldest employee of each department.  
C. Display the average age of employees of each department  
D. Display departments and the average salaries  
E. Display the lowest salary in employee table  
F. Display the number of employees working in purchase department  
G. Display the highest salary in sales department;  
H. Display the difference between highest and lowest salary 

**Table Schema: employee**
| Field Name | Data Type   | Constraints |
| :--------- | :---------- | :---------- |
| empid      | VARCHAR(4)  |             |
| ename      | VARCHAR(10) |             |
| salary     | NUMBER(8,2) |             |
| department | VARCHAR(10) |             |
| age        | NUMBER(5)   |             |

**Simulated Output:**

```sql
create table employee(empid varchar(4), ename varchar(10), salary number(8,2), department varchar(10), age number(5));
```
**Output:**
Table EMPLOYEE created.

```sql
insert into employee values('E001','A',50000,'sales',30);
```
**Output:**
1 row inserted.
```sql
insert into employee values('E002','B',50002,'purchase',34);
```
**Output:**
1 row inserted.
```sql
insert into employee values('E003','C',50034,'purchase',39);
```
**Output:**
1 row inserted.
```sql
insert into employee values('E004','D',54000,'sales',40);
```
**Output:**
1 row inserted.

```sql
select * from employee;
```
**Output:**
| EMPID | ENAME | SALARY | DEPARTMENT | AGE |
| :---- | :---- | :----- | :--------- | :-: |
| E001  | A     | 50000  | sales      | 30  |
| E002  | B     | 50002  | purchase   | 34  |
| E003  | C     | 50034  | purchase   | 39  |
| E004  | D     | 54000  | sales      | 40  |

```sql
-- A. Display the total number of employees.
select count(empid) from employee;
```
**Output:**
| COUNT(EMPID) |
| :----------- |
| 4            |

```sql
-- B. Display the name and age of the oldest employee of each department.
select department,max(age) from employee group by department;
```
**Output:**
| DEPARTMENT | MAX(AGE) |
| :--------- | :------- |
| purchase   | 39       |
| sales      | 40       |

```sql
-- C. Display the average age of employees of each department
select department, avg(age) from employee group by department;
```
**Output:**
| DEPARTMENT | AVG(AGE) |
| :--------- | :------- |
| purchase   | 36.5     |
| sales      | 35       |

```sql
-- D. Display departments and the average salaries
select department, avg(salary) from employee group by department;
```
**Output:**
| DEPARTMENT | AVG(SALARY) |
| :--------- | :---------- |
| purchase   | 50018       |
| sales      | 52000       |

```sql
-- E. Display the lowest salary in employee table
select min(salary) "Lowest Salary" from employee;
```
**Output:**
| Lowest Salary |
| :------------ |
| 50000         |

```sql
-- F. Display the number of employees working in purchase department
SELECT count(*) as total_record FROM employee WHERE department = 'purchase';
```
**Output:**
| TOTAL_RECORD |
| :----------- |
| 2            |

```sql
-- G. Display the highest salary in sales department;
select max(salary) "Maximum salary" from employee where department='sales';
```
**Output:**
| Maximum salary |
| :------------- |
| 54000          |

```sql
-- H. Display the difference between highest and lowest salary
select max(salary)-min(salary) "Difference in salary" from employee;
```
**Output:**
| Difference in salary |
| :------------------- |
| 4000                 |

---

**Question 6: Product Table**  
Create a table product with the fields (Product_code primary key, Product_Name, Category, Quantity, Price).
a. Display the records in the descending order of Product_Name  
b. Display Product_Code, Product_Name with price between 20 and 50  
c. Display the details of products which belongs to the categories of ‘bath soap’, ‘paste’, or ‘washing powder’  
d. Display the products whose Quantity less than 100 or greater than 500  
e. Display the products whose names starts with 's'  
f. Display the products which not belongs to the category 'paste'  
g. Display the products whose second letter is 'u' and belongs to the Category 'washing powder' 

**Table Schema: product**
| Field Name   | Data Type   | Constraints |
| :----------- | :---------- | :---------- |
| product_code | VARCHAR(5)  | PRIMARY KEY |
| product_name | VARCHAR(10) |             |
| category     | VARCHAR(20) |             |
| quantity     | NUMBER(5)   |             |
| price        | NUMBER(6,2) |             |

**Simulated Output:**

```sql
create table product(product_code varchar(5) primary key, product_name varchar(10), category varchar(20), quantity number(5), price number(6,2));
```
**Output:**
Table PRODUCT created.

```sql
insert into product values('P001','Sunlight','washing powder',500,150);
```
**Output:**
1 row inserted.
```sql
insert into product values('P002','Nirma','washing powder',500,120);
```
**Output:**
1 row inserted.
```sql
insert into product values('P003','Lux','soap',100,30);
```
**Output:**
1 row inserted.
```sql
insert into product values('P004','Pears','soap',100,50);
```
**Output:**
1 row inserted.
```sql
insert into product values('P005','Colgate','paste',500,50);
```
**Output:**
1 row inserted.
```sql
insert into product values('P006','ABA','cookies',500,150);
```
**Output:**
1 row inserted.
```sql
insert into product values('P007','classmate','book',600,150);
```
**Output:**
1 row inserted.
```sql
insert into product values('P008','camalin','book',50,150);
```
**Output:**
1 row inserted.

```sql
select * from product;
```
**Output:**
| PRODUCT_CODE | PRODUCT_NAME | CATEGORY        | QUANTITY | PRICE |
| :----------- | :----------- | :-------------- | :------- | :---- |
| P001         | Sunlight     | washing powder  | 500      | 150   |
| P002         | Nirma        | washing powder  | 500      | 120   |
| P003         | Lux          | soap            | 100      | 30    |
| P004         | Pears        | soap            | 100      | 50    |
| P005         | Colgate      | paste           | 500      | 50    |
| P006         | ABA          | cookies         | 500      | 150   |
| P007         | classmate    | book            | 600      | 150   |
| P008         | camalin      | book            | 50       | 150   |

```sql
-- a. Display the records in the descending order of Product_Name
select * from product order by product_name desc;
```
**Output:**
| PRODUCT_CODE | PRODUCT_NAME | CATEGORY        | QUANTITY | PRICE |
| :----------- | :----------- | :-------------- | :------- | :---- |
| P001         | Sunlight     | washing powder  | 500      | 150   |
| P004         | Pears        | soap            | 100      | 50    |
| P002         | Nirma        | washing powder  | 500      | 120   |
| P003         | Lux          | soap            | 100      | 30    |
| P007         | classmate    | book            | 600      | 150   |
| P005         | Colgate      | paste           | 500      | 50    |
| P008         | camalin      | book            | 50       | 150   |
| P006         | ABA          | cookies         | 500      | 150   |

```sql
-- b. Display Product_Code, Product_Name with price between 20 and 50
select product_code,product_name, price from product where price between 20 and 50;
```
**Output:**
| PRODUCT_CODE | PRODUCT_NAME | PRICE |
| :----------- | :----------- | :---- |
| P003         | Lux          | 30    |
| P004         | Pears        | 50    |
| P005         | Colgate      | 50    |

```sql
-- c. Display the details of products which belongs to the categories of ‘bath soap’, 'paste', or 'washing powder'
select * from product where category in('soap','paste','washing powder');
```
**Output:**
| PRODUCT_CODE | PRODUCT_NAME | CATEGORY        | QUANTITY | PRICE |
| :----------- | :----------- | :-------------- | :------- | :---- |
| P001         | Sunlight     | washing powder  | 500      | 150   |
| P002         | Nirma        | washing powder  | 500      | 120   |
| P003         | Lux          | soap            | 100      | 30    |
| P004         | Pears        | soap            | 100      | 50    |
| P005         | Colgate      | paste           | 500      | 50    |

```sql
-- d. Display the products whose Quantity less than 100 or greater than 500
select * from product where quantity<100 or quantity>500;
```
**Output:**
| PRODUCT_CODE | PRODUCT_NAME | CATEGORY | QUANTITY | PRICE |
| :----------- | :----------- | :------- | :------- | :---- |
| P007         | classmate    | book     | 600      | 150   |
| P008         | camalin      | book     | 50       | 150   |

```sql
-- e. Display the products whose names starts with 's'
select product_name from product where product_name like 'S%';
```
**Output:**
| PRODUCT_NAME |
| :----------- |
| Sunlight     |

```sql
-- f. Display the products which not belongs to the category 'paste'
select * from product where category not in ('paste');
```
**Output:**
| PRODUCT_CODE | PRODUCT_NAME | CATEGORY        | QUANTITY | PRICE |
| :----------- | :----------- | :-------------- | :------- | :---- |
| P001         | Sunlight     | washing powder  | 500      | 150   |
| P002         | Nirma        | washing powder  | 500      | 120   |
| P003         | Lux          | soap            | 100      | 30    |
| P004         | Pears        | soap            | 100      | 50    |
| P006         | ABA          | cookies         | 500      | 150   |
| P007         | classmate    | book            | 600      | 150   |
| P008         | camalin      | book            | 50       | 150   |

```sql
-- g. Display the products whose second letter is 'u' and belongs to the Category 'washing powder'
select product_name from product where product_name like '_u%' and category='washing powder';
```
**Output:**
| PRODUCT_NAME |
| :----------- |
| Sunlight     |

```sql
drop table product;
```
**Output:**
Table PRODUCT dropped.

---

**Question 7: Employee Database (city versions)**  
Consider the employee database given below. Give an expression in SQL for each of the following queries: EMPLOYEE (Employee-Name, City)  
WORKS (Employee-Name, Company-Name, Salary)  
COMPANY (Company-Name, City)  
MANAGES (Employee-Name, Manager-Name)  
A) Find the names of all employees who work in Infosys  
B) Find the names and cities of residence of all employees who works in Wipro  
C) Find the names, and cities of all employees who work in Infosys and earn more than Rs. 10,000.  
D) Find the employees who live in the same cities as the companies for which they work.  
E) Find all employees who do not work in Wipro Corporation.  
F) Find the company that has the most employees. 

**Table Schema: cityemployees1**
| Field Name | Data Type   | Constraints |
| :--------- | :---------- | :---------- |
| empname    | VARCHAR(20) | PRIMARY KEY |
| homecity   | VARCHAR(20) |             |

**Table Schema: cityempworkss1**
| Field Name  | Data Type   | Constraints                                                                 |
| :---------- | :---------- | :-------------------------------------------------------------------------- |
| empname     | VARCHAR(20) | FOREIGN KEY REFERENCES cityemployees1(empname)                              |
| companyname | VARCHAR(20) |                                                                             |
| salary      | NUMBER      |                                                                             |
|             |             | PRIMARY KEY (empname, companyname)                                          |

**Table Schema: citycompanies1**
| Field Name  | Data Type   | Constraints                                      |
| :---------- | :---------- | :----------------------------------------------- |
| companyname | VARCHAR(20) | PRIMARY KEY                                      |
| city        | VARCHAR(20) |                                                  |

**Table Schema: cityymanages1**
| Field Name  | Data Type   | Constraints                                   |
| :---------- | :---------- | :-------------------------------------------- |
| empname     | VARCHAR(20) | FOREIGN KEY REFERENCES cityemployees1(empname), PRIMARY KEY |
| managername | VARCHAR(20) |                                               |

**Simulated Output:**

```sql
create table cityemployees1(empname varchar(20) primary key, homecity varchar(20));
```
**Output:**
Table CITYEMPLOYEES1 created.

```sql
create table cityempworkss1(empname varchar(20), companyname varchar(20), salary number, 
                            foreign key(empname) references cityemployees1(empname), 
                            primary key(empname, companyname));
```
**Output:**
Table CITYEMPWOKSS1 created.

```sql
create table citycompanies1(companyname varchar(20) primary key, city varchar(20));
```
**Output:**
Table CITYCOMPANIES1 created.

```sql
create table cityymanages1(empname varchar(20) primary key, managername varchar(20), 
                           foreign key(empname) references cityemployees1(empname));
```
**Output:**
Table CITYYMANAGES1 created.

```sql
insert into cityemployees1 values('resmi','ferook');
```
**Output:** 1 row inserted.
```sql
insert into cityemployees1 values('shirin','marikunnu');
```
**Output:** 1 row inserted.
```sql
insert into cityemployees1 values('jasna','narikunil');
```
**Output:** 1 row inserted.
```sql
insert into cityemployees1 values('anu','kovoor');
```
**Output:** 1 row inserted.
```sql
insert into cityemployees1 values('anju','pottammal');
```
**Output:** 1 row inserted.
```sql
insert into cityemployees1 values('nimisha','unknown');
```
**Output:** 1 row inserted.

```sql
select * from cityemployees1;
```
**Output:**
| EMPNAME   | HOMECITY   |
| :-------- | :--------- |
| resmi     | ferook     |
| shirin    | marikunnu  |
| jasna     | narikunil  |
| anu       | kovoor     |
| anju      | pottammal  |
| nimisha   | unknown    |


```sql
insert into cityempworkss1 values('resmi','Infosys',50000);
```
**Output:** 1 row inserted.
```sql
insert into cityempworkss1 values('shirin','Infosys',52000);
```
**Output:** 1 row inserted.
```sql
insert into cityempworkss1 values('jasna','Wipro',54000);
```
**Output:** 1 row inserted.
```sql
insert into cityempworkss1 values('anu','Lenovo',58000);
```
**Output:** 1 row inserted.
```sql
insert into cityempworkss1 values('anju','Lenovo',51000);
```
**Output:** 1 row inserted.

```sql
select * from cityempworkss1;
```
**Output:**
| EMPNAME | COMPANYNAME | SALARY |
| :------ | :---------- | :----- |
| resmi   | Infosys     | 50000  |
| shirin  | Infosys     | 52000  |
| jasna   | Wipro       | 54000  |
| anu     | Lenovo      | 58000  |
| anju    | Lenovo      | 51000  |

```sql
insert into citycompanies1 values('Infosys','mumbai');
```
**Output:** 1 row inserted.
```sql
insert into citycompanies1 values('Wipro','kolkatta');
```
**Output:** 1 row inserted.
```sql
insert into citycompanies1 values('Lenovo','mysore');
```
**Output:** 1 row inserted.

```sql
select * from citycompanies1;
```
**Output:**
| COMPANYNAME | CITY     |
| :---------- | :------- |
| Infosys     | mumbai   |
| Wipro       | kolkatta |
| Lenovo      | mysore   |

```sql
insert into cityymanages1 values('resmi','ram');
```
**Output:** 1 row inserted.
```sql
insert into cityymanages1 values('shirin','sam');
```
**Output:** 1 row inserted.
```sql
insert into cityymanages1 values('jasna','alex');
```
**Output:** 1 row inserted.
```sql
insert into cityymanages1 values('nimisha','john');
```
**Output:** 1 row inserted.
```sql
insert into cityymanages1 values('anju','maria');
```
**Output:** 1 row inserted.

```sql
select * from cityymanages1;
```
**Output:**
| EMPNAME   | MANAGERNAME |
| :-------- | :---------- |
| resmi     | ram         |
| shirin    | sam         |
| jasna     | alex        |
| nimisha   | john        |
| anju      | maria       |

```sql
-- A) Find the names of all employees who work in Infosys
SELECT empname FROM cityempworkss1 WHERE companyname='Infosys';
```
**Output:**
| EMPNAME |
| :------ |
| resmi   |
| shirin  |

```sql
-- B) Find the names and cities of residence of all employees who works in Wipro
SELECT e.empname, e.homecity FROM cityemployees1 e JOIN cityempworkss1 w ON e.empname = w.empname WHERE w.companyname='Wipro';
```
**Output:**
| EMPNAME | HOMECITY  |
| :------ | :-------- |
| jasna   | narikunil |

```sql
-- C) Find the names, and cities of all employees who work in Infosys and earn more than Rs. 10,000.
SELECT w.empname, c.city 
FROM cityempworkss1 w 
JOIN citycompanies1 c ON w.companyname = c.companyname 
WHERE w.companyname='Infosys' AND w.salary > 10000;
```
**Output:**
| EMPNAME | CITY   |
| :------ | :----- |
| resmi   | mumbai |
| shirin  | mumbai |

```sql
-- D) Find the employees who live in the same cities as the companies for which they work.
SELECT e.empname 
FROM cityemployees1 e 
JOIN cityempworkss1 w ON e.empname = w.empname 
JOIN citycompanies1 co ON w.companyname = co.companyname 
WHERE e.homecity = co.city;
```
**Output:**
0 rows selected

```sql
-- E) Find all employees who do not work in Wipro Corporation.
SELECT empname 
FROM cityemployees1 
WHERE empname NOT IN (SELECT empname FROM cityempworkss1 WHERE companyname = 'Wipro');
```
**Output:**
| EMPNAME |
| :------ |
| resmi   |
| shirin  |
| anu     |
| anju    |
| nimisha |


```sql
-- F) Find the company that has the most employees.
WITH CompanyEmployeeCounts AS (
    SELECT companyname, COUNT(empname) as num_employees
    FROM cityempworkss1
    GROUP BY companyname
)
SELECT companyname
FROM CompanyEmployeeCounts
WHERE num_employees = (SELECT MAX(num_employees) FROM CompanyEmployeeCounts);
```
**Output:**
| COMPANYNAME |
| :---------- |
| Infosys     |
| Lenovo      |

---

**Question 8: Supplier (PL/SQL)**

Create table supplier(supcode,sname,city) Create table product (pcode,pname) Create table supl_product(supcode,pcode,qty)
a) Get all pairs of supplier numbers such that the two suppliers are located in the same city.  
b) Get supplier names for suppliers who supply product P2.  
c) Get product numbers supplied by more than one supplier.  
d) Get supplier numbers for suppliers who are located in the same city as supplier S1.  
e) Get supplier names for suppliers who supply part P1.  
f) Get the number of Suppliers, who are supplying at least one product.  
g) For each product supplied, get the pcode. and the total quantity supplied for that part. 

---

**Question 9: Salary Report (PL/SQL)**

Prepare a salary report of the employees showing the details such as: EmpNo, Name, Basic Pay, DA, Gross Salary, PF, Net Salary, Annual Salary and Tax For this purpose, create a table named SALARIES having the following structure.

| Field Name | Type | Width |
| :--------- | :--- | :---- |
| EmpNo | Character | 10    |
| Name  | Character | 20    |
| Basic | Numeric   | 6     |

Enter the records of at least 10 employees. Use the following information for calculating the details for the report:  
DA is fixed as the 40% of the basic pay.  
PF is fixed as 10% of the basic pay.  
Gross Salary = Basic Pay + DA.  
Net Salary = Gross Salary – PF  
Annual Salary = 12 * Net Salary  
Tax is calculated using the following rules:  
If annual salary is less than 100000, No Tax  
If annual salary is greater than 100000 but less than or equal to 150000, then the tax is 10% of the excess over 100000.  
If annual salary is greater than 150000 but less than or equal to 250000, then the tax is 20% of the excess over 150000.  
If annual salary is greater than 250000, then the tax is 30% of the excess over 250000.

**Table Schema: emp_salary**
| Field Name  | Data Type | Constraints |
| :---------- | :-------- | :---------- |
| emp_no      | NUMBER(5) |             |
| name        | CHAR(15)  |             |
| basic_pay   | NUMBER(10)|             |
| DA          | NUMBER(10)|             |
| GS          | NUMBER(10)|             |
| PF          | NUMBER(10)|             |
| Netsalary   | NUMBER(10)|             |
| annualsal   | NUMBER(10)|             |
| tax         | NUMBER(10)|             |

**Simulated Output:**

```sql
Create table emp_salary( emp_no number(5),name char(15),basic_pay number(10),DA number(10),GS number(10),PF number(10),Netsalary number(10),annualsal number(10),tax number(10));
```
**Output:**
Table EMP_SALARY created.

```sql
Insert into emp_salary(emp_no,name,basic_pay) values(12, 'mohan', 200000);
```
**Output:**
1 row inserted.

```sql
set serveroutput on;
```
**Output:**
*(No direct output)*

```sql
create or replace function tax(annual_salary IN number) return number is -- Renamed to TAX as per PDF implication
  calculated_tax number(10);
begin
  if annual_salary < 100000 then
    calculated_tax := 0;
  elsif annual_salary <= 150000 then
    calculated_tax := 0.1 * (annual_salary - 100000);
  elsif annual_salary <= 250000 then
    calculated_tax := 0.2 * (annual_salary - 150000);
  else
    calculated_tax := 0.3 * (annual_salary - 250000);
  end if;
  return calculated_tax;
end;
/
```
**Output:**
Function TAX compiled.

```sql
declare
  cursor c_emp is select emp_no, name, basic_pay from emp_salary;
  v_emp_no emp_salary.emp_no%type;
  v_name emp_salary.name%type;
  v_basic_pay emp_salary.basic_pay%type;
  v_da emp_salary.DA%type;
  v_pf emp_salary.PF%type;
  v_gs emp_salary.GS%type;
  v_netsalary emp_salary.Netsalary%type;
  v_annualsal emp_salary.annualsal%type;
  v_tax emp_salary.tax%type;
begin
  open c_emp;
  loop
    fetch c_emp into v_emp_no, v_name, v_basic_pay;
    exit when c_emp%notfound;
    
    v_da := v_basic_pay * 0.4;
    v_pf := v_basic_pay * 0.1;
    v_gs := v_basic_pay + v_da;
    v_netsalary := v_gs - v_pf;
    v_annualsal := 12 * v_netsalary;
    v_tax := tax(v_annualsal); -- Using the created function TAX
    
    update emp_salary 
    set DA=v_da, PF=v_pf, GS=v_gs, Netsalary=v_netsalary, annualsal=v_annualsal, tax=v_tax 
    where emp_no = v_emp_no;
  end loop;
  close c_emp;
end;
/
```
**Output:**
PL/SQL procedure successfully completed.

```sql
select * from emp_salary where emp_no = 12;
```
**Output:**
| EMP_NO | NAME    | BASIC_PAY | DA    | GS     | PF    | NETSALARY | ANNUALSAL | TAX    |
| :----- | :------ | :-------- | :---- | :----- | :---- | :-------- | :-------- | :----- |
| 12     | mohan   | 200000    | 80000 | 280000 | 20000 | 260000    | 3120000   | 861000 |

---

**Question 10: Exam Result (PL/SQL)**

Create table exam_result(rollno, avg_score, Grade)  
insert 10 records.  
Assign null values to the field grade.  
Write Program block to update the grade field by using the following condition.  
avg_score between 90 and 100 = A  
avg_score 75 -89 = B  
avg_score 60- 74 = C  
avg_score 50 -59 = D  
avg_score below 50 = F  

**Table Schema: stud4**
(after alter)
| Field Name | Data Type    | Constraints |
| :--------- | :----------- | :---------- |
| regno      | NUMBER(5)    |             |
| name       | VARCHAR2(20) |             |
| score1     | NUMBER(4)    |             |
| score2     | NUMBER(4)    |             |
| score3     | NUMBER(4)    |             |
| score4     | NUMBER(4)    |             |
| total      | NUMBER(5)    | NULL        |
| avg        | NUMBER       | NULL        |
| grade      | CHAR(15)     | NULL        |
| sub1       | NUMBER(3)    |             |
| sub2       | NUMBER(3)    |             |
| sub3       | NUMBER(3)    |             |
| sub4       | NUMBER(3)    |             |

**Simulated Output:**

```sql
create table stud4(regno number(5),name varchar2(20),score1 number(4),score2 number(4),score3 number(4),score4 number(4),total number(5) null,avg number null, grade char(15) null);
```
**Output:**
Table STUD4 created.

```sql
insert into stud4(regno,name,score1,score2,score3,score4)values(12,'saavi',21,22,32,21);
```
**Output:**
1 row inserted.

```sql
alter table stud4 add(sub1 number(3),sub2 number(3),sub3 number(3),sub4 number(3));
```
**Output:**
Table STUD4 altered.

```sql
create or replace function givegrade(p in number) return char is -- Named GIVEGRADE as per PDF
  g char(15);
begin
  if p >= 70 then -- PDF logic for Q10 grading A,B,C,D
    g:='A';
  elsif p >= 60 then
    g:='B';
  elsif p>= 50 then
    g:='C';
  else
    g:='D';
  end if;
  return g;
end;
/
```
**Output:**
Function GIVEGRADE created.

```sql
set serveroutput on;
```
**Output:**
*(No direct output)*

```sql
declare
  cursor c_grade is select regno,name,score1,score2,score3,score4 from stud4 where regno=12;
  v_no stud4.regno%type;
  v_n stud4.name%type;
  v_s1 stud4.score1%type;
  v_s2 stud4.score2%type;
  v_s3 stud4.score3%type;
  v_s4 stud4.score4%type;
  v_t number;
  v_p number;
  v_g varchar2(20);
begin
  open c_grade;
  loop
    fetch c_grade into v_no,v_n,v_s1,v_s2,v_s3,v_s4;
    exit when c_grade%notfound;
    v_t:=v_s1+v_s2+v_s3+v_s4;
    v_p:=v_t/4;
    v_g:=givegrade(v_p); -- Using the GIVEGRADE for Q10
    update stud4 set total=v_t,avg=v_p,grade=v_g where regno=v_no;
  end loop;
  close c_grade;
end;
/
```
**Output:**
PL/SQL procedure successfully completed.

```sql
select regno, name, score1, score2, score3, score4, total, avg, grade from stud4 where regno=12;
```
**Output:**
| REGNO | NAME  | SCORE1 | SCORE2 | SCORE3 | SCORE4 | TOTAL | AVG | GRADE |
| :---- | :---- | :----- | :----- | :----- | :----- | :---- | :-- | :---- |
| 12    | saavi | 21     | 22     | 32     | 21     | 96    | 24  | D     |

---

**Question 11: Area of Circle (PL/SQL)**

Write a program code to calculate the area of a circle for a value of radius varying from 3 to 7. Store the radius and the corresponding value of calculated area in an empty table named areas with field’s radius and area.  

**Table Schema: area**
| Field Name | Data Type   | Constraints |
| :--------- | :---------- | :---------- |
| radius     | NUMBER(5,2) |             |
| area_val   | NUMBER(10,2)|             | (Column name changed to avoid conflict with table name in PL/SQL block)

**Simulated Output:**

```sql
create table area(radius number(5,2), area_val number(10,2)); -- Changed column name
```
**Output:**
Table AREA created.

```sql
declare
  r_val number; -- Changed variable name to avoid conflict
  a_val number(10,2);
begin
  for r_loop_idx in 3..7 loop -- Changed loop variable
    a_val:=3.14*r_loop_idx*r_loop_idx;
    insert into area values(r_loop_idx,a_val);
  end loop;
end;
/
```
**Output:**
PL/SQL procedure successfully completed.

```sql
select * from area;
```
**Output:**
| RADIUS | AREA_VAL |
| :----- | :------- |
| 3      | 28.26    |
| 4      | 50.24    |
| 5      | 78.50    |
| 6      | 113.04   |
| 7      | 153.86   |

---

**Question 12: Electricity Bill (PL/SQL)**

Write a program block to calculate the  electricity bill by accepting cust_no and units_consumed

**Table Schema: elec_bill**
| Field Name     | Data Type    | Constraints |
| :------------- | :----------- | :---------- |
| cust_no        | NUMBER       | PRIMARY KEY |
| cust_name      | VARCHAR2(20) |             |
| units_consumed | NUMBER       |             |
| bill_amt       | NUMBER       |             |

**Simulated Output:**

```sql
create table elec_bill(cust_no number primary key,cust_name varchar2(20),units_consumed number,bill_amt number);
```
**Output:**
Table ELEC_BILL created.

```sql
insert into elec_bill(cust_no,cust_name,units_consumed)values(1,'Ram',2134);
```
**Output:** 1 row inserted.
```sql
insert into elec_bill(cust_no,cust_name,units_consumed)values(2,'Raj',2456);
```
**Output:** 1 row inserted.
```sql
insert into elec_bill(cust_no,cust_name,units_consumed)values(3,'Sam',2331);
```
**Output:** 1 row inserted.
```sql
insert into elec_bill(cust_no,cust_name,units_consumed)values(4,'Pam',1244);
```
**Output:** 1 row inserted.
```sql
insert into elec_bill(cust_no,cust_name,units_consumed)values(5,'Jhon',2566);
```
**Output:** 1 row inserted.

```sql
select * from elec_bill;
```
**Output:**
| CUST_NO | CUST_NAME | UNITS_CONSUMED | BILL_AMT |
| :------ | :-------- | :------------- | :------- |
| 1       | Ram       | 2134           |          |
| 2       | Raj       | 2456           |          |
| 3       | Sam       | 2331           |          |
| 4       | Pam       | 1244           |          |
| 5       | Jhon      | 2566           |          |

```sql
create or replace function calc(b in number) return number is -- Named CALC as per PDF
  c number;
begin
  if(b<=40)then
    c:=b*15;
  elsif(b<=80)then
    c:=b*40;
  else
    c:=b*80;
  end if;
  return c;
end;
/
```
**Output:**
Function CALC created.

```sql
set serveroutput on;
```
**Output:**
*(No direct output)*

```sql
declare
  cursor c_calc is select cust_no, units_consumed from elec_bill;
  v_c number; 
begin
  for rec in c_calc loop
    v_c:=calc(rec.units_consumed); -- Using function CALC
    update elec_bill set bill_amt=v_c where cust_no=rec.cust_no;
  end loop;
end;
/
```
**Output:**
PL/SQL procedure successfully completed.

```sql
select * from elec_bill order by cust_no;
```
**Output:**
| CUST_NO | CUST_NAME | UNITS_CONSUMED | BILL_AMT |
| :------ | :-------- | :------------- | :------- |
| 1       | Ram       | 2134           | 170720   |
| 2       | Raj       | 2456           | 196480   |
| 3       | Sam       | 2331           | 186480   |
| 4       | Pam       | 1244           | 99520    |
| 5       | Jhon      | 2566           | 205280   |

---

**Question 13: Fibonacci Series (PL/SQL Procedure)**

Create a procedure to print Fibonacci number up to a limit, limit is passed as an argument

**Simulated Output:**

```sql
CREATE OR REPLACE PROCEDURE fibonacci (p_n IN NUMBER) IS -- Named FIBONACCI as per PDF
  first_num NUMBER := 0;
  second_num NUMBER := 1;
  third_num NUMBER;
BEGIN
  DBMS_OUTPUT.PUT_LINE('Fibonacci series is:');
  IF p_n >= 1 THEN
    DBMS_OUTPUT.PUT_LINE(first_num);
  END IF;
  IF p_n >= 2 THEN
    DBMS_OUTPUT.PUT_LINE(second_num);
  END IF;
  FOR i IN 3..p_n LOOP 
    third_num := first_num + second_num;
    DBMS_OUTPUT.PUT_LINE(third_num);
    first_num := second_num;
    second_num := third_num;
  END LOOP;
END;
/
```
**Output:**
Procedure FIBONACCI created.

```sql
set serveroutput on;
```
**Output:**
*(No direct output)*

```sql
declare
  n_val number:= 7; 
begin
  fibonacci(n_val); -- Calling procedure FIBONACCI
end;
/
```
**Output:**
Fibonacci series is:
0
1
1
2
3
5
8
PL/SQL procedure successfully completed.

---

**Question 14: Check Prime Number (SQL Query)**

Create a function to check whether a given number is prime or not

**Simulated Output:**

```sql
with num as (
  select level n
  from dual
  connect by level <= 30
),
prime_candidates as (
  select n,
    case
      when n = 1 then 'no prime'
      when n = 2 then 'prime'
      when mod(n, 2) = 0 and n > 2 then 'no prime'
      when not exists (
        select null
        from num n_inner
        where n_inner.n > 1
          and n_inner.n <= sqrt(num.n)
          and mod(num.n, n_inner.n) = 0
      ) then 'prime'
      else 'no prime'
    end is_prime
  from num
)
select listagg(b.n,'-') within group(order by b.n) as primes
from prime_candidates b
where b.is_prime='prime' and b.n!=1;
```
**Output:**
| PRIMES                      |
| :-------------------------- |
| 2-3-5-7-11-13-17-19-23-29   |

---

**Question 15: Student Marks Count (PL/SQL Procedure)**

create a table stud_mark(regno, sname  ,avg_mark) Insert few records  Write a procedure to display number of students got Distinction, first-class, second class, third class or failed (90-100 distinction, 75-89 firstclass 60-74 second class 50-59 Third class below 50 failed)

**Table Schema: stud4** (Reusing from Q10, but with `grade VARCHAR2(15)`)

**Simulated Output:**

```sql
TRUNCATE TABLE stud4;
```
**Output:**
Table STUD4 truncated.
```sql
ALTER TABLE stud4 MODIFY grade VARCHAR2(15); -- Ensure grade can hold 'Distinction' etc.
```
**Output:**
Table STUD4 altered.

```sql
insert into stud4(regno,name,score1,score2,score3,score4)values(1,'saavi',21,22,32,21);
```
**Output:** 1 row inserted.
```sql
insert into stud4(regno,name,score1,score2,score3,score4)values(2,'Raj',80,85,90,75);
```
**Output:** 1 row inserted.
```sql
insert into stud4(regno,name,score1,score2,score3,score4)values(3,'Amit',50,55,60,65);
```
**Output:** 1 row inserted.
```sql
insert into stud4(regno,name,score1,score2,score3,score4)values(4,'Sita',30,35,40,45);
```
**Output:** 1 row inserted.
```sql
insert into stud4(regno,name,score1,score2,score3,score4)values(5,'John',90,92,95,88);
```
**Output:** 1 row inserted.
```sql
insert into stud4(regno,name,score1,score2,score3,score4)values(6,'Geeta',65,70,72,68);
```
**Output:** 1 row inserted.


```sql
create or replace function givegrade(p in number) return varchar2 is -- Named GIVEGRADE as per PDF (Q15 version)
  g varchar2(15);
begin
  if p >= 70 then       -- PDF Q15 logic: 70+ Distinction
    g:='Distinction';
  elsif p >= 60 then    -- 60-69 First (PDF says 75-89 firstclass, 60-74 second for Q15 problem desc. Using page 14's function logic)
    g:='First';         -- This matches page 14's function logic
  elsif p>= 50 then     -- 50-59 Pass
    g:='Pass';
  else                  -- Below 50 Fail
    g:='Fail';
  end if;
  return g;
end;
/
```
**Output:**
Function GIVEGRADE created.

```sql
set serveroutput on;
```
**Output:**
*(No direct output)*

```sql
declare
  cursor c_stud is select regno, score1, score2, score3, score4 from stud4;
  v_total stud4.total%type;
  v_avg stud4.avg%type;
  v_grade stud4.grade%type;
begin
  for rec in c_stud loop
    v_total := rec.score1 + rec.score2 + rec.score3 + rec.score4;
    v_avg := v_total / 4;
    v_grade := givegrade(v_avg); -- Using GIVEGRADE for Q15
    update stud4 set total = v_total, avg = v_avg, grade = v_grade where regno = rec.regno;
  end loop;
end;
/
```
**Output:**
PL/SQL procedure successfully completed.

```sql
CREATE OR REPLACE PROCEDURE display_grade_counts IS -- Generic name
  v_distinction_count NUMBER := 0;
  v_first_count NUMBER := 0;
  v_pass_count NUMBER := 0;
  v_fail_count NUMBER := 0;
BEGIN
  SELECT COUNT(CASE WHEN grade = 'Distinction' THEN 1 END),
         COUNT(CASE WHEN grade = 'First' THEN 1 END),
         COUNT(CASE WHEN grade = 'Pass' THEN 1 END),
         COUNT(CASE WHEN grade = 'Fail' THEN 1 END)
  INTO v_distinction_count, v_first_count, v_pass_count, v_fail_count
  FROM stud4;

  DBMS_OUTPUT.PUT_LINE('Distinction: ' || v_distinction_count);
  DBMS_OUTPUT.PUT_LINE('First: ' || v_first_count);
  DBMS_OUTPUT.PUT_LINE('Pass: ' || v_pass_count);
  DBMS_OUTPUT.PUT_LINE('Fail: ' || v_fail_count);
END;
/
```
**Output:**
Procedure DISPLAY_GRADE_COUNTS created.

```sql
begin
  display_grade_counts;
end;
/
```
**Output:**
Distinction: 2
First: 1
Pass: 1
Fail: 2
PL/SQL procedure successfully completed.

---

**Question 18: Trigger**

create table phonebook (pname, mobno)  Create a Trigger to insert the old records from the table phonebook to del_phonebook (pname, mobno, modfy_date) whenever a record is deleted or updated in the phonebook table. 

**Table Schemas:**
**phonebook:**
| Column Name | Data Type   | Constraints |
| :---------- | :---------- | :---------- |
| pname       | VARCHAR(20) |             |
| mobno       | NUMBER(10)  |             |

**del_phonebook:**
| Column Name | Data Type   | Constraints |
| :---------- | :---------- | :---------- |
| pname       | VARCHAR(20) |             |
| mobno       | NUMBER(10)  |             |
| modfy_date  | DATE        |             |

**Simulated Output:**

```sql
CREATE TABLE phonebook(
    pname VARCHAR(20),
    mobno NUMBER(10)
);
```
**Output:**
Table PHONEBOOK created.

```sql
INSERT INTO phonebook VALUES('a', 1234);
```
**Output:**
1 row inserted.

```sql
INSERT INTO phonebook VALUES('b', 1235);
```
**Output:**
1 row inserted.

```sql
INSERT INTO phonebook VALUES('c', 1236);
```
**Output:**
1 row inserted.

```sql
INSERT INTO phonebook VALUES('d', 1237);
```
**Output:**
1 row inserted.

```sql
CREATE TABLE del_phonebook(
    pname VARCHAR(20),
    mobno NUMBER(10),
    modfy_date DATE
);
```
**Output:**
Table DEL_PHONEBOOK created.

```sql
CREATE OR REPLACE TRIGGER phone_tir
BEFORE DELETE OR UPDATE ON phonebook
FOR EACH ROW
BEGIN
    INSERT INTO del_phonebook (pname, mobno, modfy_date)
    VALUES (:old.pname, :old.mobno, SYSDATE);
END;
/
```
**Output:**
Trigger PHONE_TIR created.

```sql
DELETE FROM phonebook WHERE pname='a';
```
**Output:**
1 row deleted.

```sql
UPDATE phonebook SET mobno = 123 WHERE pname = 'b';
```
**Output:**
1 row updated.

```sql
SELECT * FROM del_phonebook;
```
**Output (assuming both DML operations happened on '29-MAY-2025'):**
| PNAME  | MOBNO | MODFY_DATE |
| :----- | :---- | :--------- |
| a      | 1234  | 29-MAY-25  |
| b      | 1235  | 29-MAY-25  |
