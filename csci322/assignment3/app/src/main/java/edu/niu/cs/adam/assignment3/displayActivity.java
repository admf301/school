/*
* ***SOURCES ARE INCLUDED IN THE INFO[] STRINGS***
*          THEY ARE ALL FROM WIKIPEDIA
* sources:
* https://en.wikipedia.org/wiki/C%2B%2B
* https://en.wikipedia.org/wiki/SQL
* https://en.wikipedia.org/wiki/Java_(programming_language)
* https://en.wikipedia.org/wiki/PHP
* https://en.wikipedia.org/wiki/Python_(programming_language)
*/

package edu.niu.cs.adam.assignment3;

import androidx.appcompat.app.AppCompatActivity;

import android.annotation.SuppressLint;
import android.content.Intent;
import android.os.Bundle;
import android.text.method.ScrollingMovementMethod;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class displayActivity extends AppCompatActivity {

    public static String string_id[] = {"C++", "SQL", "Java", "PHP", "Python"};
    public static String info[] =   { //sorry about this, idk how to access a strings.xml array
/*0*/ "C++ is a high-level, general-purpose programming language created by Danish computer scientist Bjarne Stroustrup. First released in 1985 as an extension of the C programming language, it has since expanded significantly over time; modern C++ currently has object-oriented, generic, and functional features, in addition to facilities for low-level memory manipulation. It is almost always implemented as a compiled language, and many vendors provide C++ compilers, including the Free Software Foundation, LLVM, Microsoft, Intel, Embarcadero, Oracle, and IBM.\n" +
            "\n" +
            "C++ was designed with systems programming and embedded, resource-constrained software and large systems in mind, with performance, efficiency, and flexibility of use as its design highlights. C++ has also been found useful in many other contexts, with key strengths being software infrastructure and resource-constrained applications, including desktop applications, video games, servers (e.g. e-commerce, web search, or databases), and performance-critical applications (e.g. telephone switches or space probes). Source: https://en.wikipedia.org/wiki/C%2B%2B",
/*1*/ "Structured Query Language, abbreviated as SQL, is a domain-specific language used in programming and designed for managing data held in a relational database management system (RDBMS), or for stream processing in a relational data stream management system (RDSMS). It is particularly useful in handling structured data, i.e. data incorporating relations among entities and variables.\n" +
            "\n" +
            "SQL offers two main advantages over older read–write APIs such as ISAM or VSAM. Firstly, it introduced the concept of accessing many records with one single command. Secondly, it eliminates the need to specify how to reach a record, e.g. with or without an index.\n" +
            "\n" +
            "Originally based upon relational algebra and tuple relational calculus, SQL consists of many types of statements, which may be informally classed as sublanguages, commonly: a data query language (DQL), a data definition language (DDL), a data control language (DCL), and a data manipulation language (DML). The scope of SQL includes data query, data manipulation (insert, update, and delete), data definition (schema creation and modification), and data access control. Although SQL is essentially a declarative language (4GL), it also includes procedural elements.\n" +
            "\n" +
            "SQL was one of the first commercial languages to use Edgar F. Codd’s relational model. The model was described in his influential 1970 paper, \"A Relational Model of Data for Large Shared Data Banks\". Despite not entirely adhering to the relational model as described by Codd, it became the most widely used database language. Source: https://en.wikipedia.org/wiki/SQL",
/*2*/ "Java is a high-level, class-based, object-oriented programming language that is designed to have as few implementation dependencies as possible. It is a general-purpose programming language intended to let programmers write once, run anywhere (WORA), meaning that compiled Java code can run on all platforms that support Java without the need to recompile. Java applications are typically compiled to bytecode that can run on any Java virtual machine (JVM) regardless of the underlying computer architecture. The syntax of Java is similar to C and C++, but has fewer low-level facilities than either of them. The Java runtime provides dynamic capabilities (such as reflection and runtime code modification) that are typically not available in traditional compiled languages. As of 2019, Java was one of the most popular programming languages in use according to GitHub, particularly for client–server web applications, with a reported 9 million developers.\n" +
            "\n" +
            "Java was originally developed by James Gosling at Sun Microsystems. It was released in May 1995 as a core component of Sun Microsystems' Java platform. The original and reference implementation Java compilers, virtual machines, and class libraries were originally released by Sun under proprietary licenses. As of May 2007, in compliance with the specifications of the Java Community Process, Sun had relicensed most of its Java technologies under the GPL-2.0-only license. Oracle offers its own HotSpot Java Virtual Machine, however the official reference implementation is the OpenJDK JVM which is free open-source software and used by most developers and is the default JVM for almost all Linux distributions. Source: https://en.wikipedia.org/wiki/Java_(programming_language)",
/*3*/ "PHP is a general-purpose scripting language geared toward web development. It was originally created by Danish-Canadian programmer Rasmus Lerdorf in 1993 and released in 1995. The PHP reference implementation is now produced by The PHP Group. PHP was originally an abbreviation of Personal Home Page, but it now stands for the recursive initialism PHP: Hypertext Preprocessor.\n" +
            "\n" +
            "PHP code is usually processed on a web server by a PHP interpreter implemented as a module, a daemon or as a Common Gateway Interface (CGI) executable. On a web server, the result of the interpreted and executed PHP code – which may be any type of data, such as generated HTML or binary image data – would form the whole or part of an HTTP response. Various web template systems, web content management systems, and web frameworks exist which can be employed to orchestrate or facilitate the generation of that response. Additionally, PHP can be used for many programming tasks outside the web context, such as standalone graphical applications and robotic drone control. PHP code can also be directly executed from the command line.\n" +
            "\n" +
            "The standard PHP interpreter, powered by the Zend Engine, is free software released under the PHP License. PHP has been widely ported and can be deployed on most web servers on a variety of operating systems and platforms. Source: https://en.wikipedia.org/wiki/PHP",
/*4*/ "Python is a high-level, general-purpose programming language. Its design philosophy emphasizes code readability with the use of significant indentation.\n" +
            "\n" +
            "Python is dynamically typed and garbage-collected. It supports multiple programming paradigms, including structured (particularly procedural), object-oriented and functional programming. It is often described as a \"batteries included\" language due to its comprehensive standard library.\n" +
            "\n" +
            "Guido van Rossum began working on Python in the late 1980s as a successor to the ABC programming language and first released it in 1991 as Python 0.9.0. Python 2.0 was released in 2000. Python 3.0, released in 2008, was a major revision not completely backward-compatible with earlier versions. Python 2.7.18, released in 2020, was the last release of Python 2.\n" +
            "\n" +
            "Python consistently ranks as one of the most popular programming languages. Source: https://en.wikipedia.org/wiki/Python_(programming_language)"
                                    };
    private Button returnBtn;
    private TextView displayTV, infoTV;
    int extraSelect = 0;

    @SuppressLint("MissingInflatedId")
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_display);

        returnBtn = findViewById(R.id.returnButton);
        displayTV = findViewById(R.id.displayTextView);
        infoTV = findViewById(R.id.infoTextView);

        Bundle extras = getIntent().getExtras();
        extraSelect = extras.getInt("select");

        infoTV.setMovementMethod(new ScrollingMovementMethod());
        displayTV.setText(string_id[extraSelect]);
        infoTV.setText(info[extraSelect]);
    }

    public void goToMain(View view) {
        finish();
    }
}