
BEGIN {

	printf ("%-22s%-22s%s\n", "Name" , "Title", "Salary");
	print "=====================================================";
	#set field separator to :
	FS = ":";
}
{

	#if the number of fields is 5, its an employee
	if (NF == 5 && !/#/)
	{
		#employee[empid] = name/title/salary
		employee[$2] = $3;
		title[$2] = $4;
		salary[$2] = $5;
		empcount++;
		total_salary = total_salary + $5;
	}
	#if the number of fields is 4, its a project
	else if (NF == 4 && !/#/)
	{
		project[$2] = $3;
		projcount++;
	}

}
END {
	#print out the report
	for (i in employee)
	{
		printf("%-22s%-22s%s\n", employee[i], title[i], salary[i]) | "sort -k5 -nr";
	}
	close("sort -k5 -nr");

	print "====================================================";
	print "Employees:\t" empcount "\t Projects:\t" (projcount - 12);
	print "Total Salary:\t\t $" total_salary ".00";
	printf ("%s%10.2f\n", "Employee Average Salary: $", (total_salary/empcount));

	print"====================================================";
}
