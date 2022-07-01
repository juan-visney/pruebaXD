#ifndef ESTUDIANTE_H_INCLUDED
#define ESTUDIANTE_H_INCLUDED

#include<string.h>
#include<cstdio>

using namespace std;

struct Fecha {
    int dia;
    int mes;
    int anio;
    Fecha(){
        dia = 1;
        mes = 1;
        anio = 1900;
    }
    friend istream &operator >> (istream &i, Fecha &f) {
        char c;
        i>>f.dia>>c>>f.mes>>c>>f.anio;
        return i;
    }
    friend ostream &operator << (ostream &o, Fecha &f) {
        o<<f.dia<<"/"<<f.mes<<"/"<<f.anio;
        return o;
    }
};

struct Materia{
    double nota;
    char sigla[10];
    char nombre[50];
    char docente[20];
    char paralelo;
    Materia() {
        nota = 0;
        strcpy(sigla, "_sigla");
        strcpy(nombre, "_nombre");
        strcpy(docente, "_docente");
        paralelo = '_';
    }
    friend istream &operator >> (istream &i, Materia &m) {
        cout << "Ingrese nota: ";
        i >> m.nota;
        fflush(stdin);
        cout << "Ingrese sigla: ";
        gets(m.sigla);
        cout << "Ingrese nombre: ";
        gets(m.nombre);
        cout << "Ingrese docente: ";
        gets(m.docente);
        cout << "Ingrese paralelo: ";
        i >> m.paralelo;
        return i;
    }
    friend ostream &operator << (ostream &o, Materia &m) {
        o << "Nota: " << m.nota << endl;
        o << "Sigla: " << m.sigla << endl;
        o << "Nombre: " << m.nombre << endl;
        o << "Docente: " << m.docente << endl;
        o << "Paralelo: " << m.paralelo << endl;
        return o;
    }
};

struct Estudiante{
    int ci;
    char nombre[30];
    char carrera[20];
    Fecha fechaNacimiento;
    int matricula;
    int cantMaterias;
    Materia materias[8];

    Estudiante() {
        ci = 0;
        strcpy(nombre, "_nombre");
        strcpy(carrera, "_carrera");
        matricula = 10000;
        cantMaterias = 0;
    }

    friend istream &operator >> (istream &i, Estudiante &e) {
        cout << "Ingrese CI: ";
        i >> e.ci;
        cin.ignore();
        cout << "Ingrese nombre: ";
        gets(e.nombre);
        cout << "Ingrese carrera: ";
        gets(e.carrera);
        cout << "Ingrese fecha de nacimiento: ";
        i >> e.fechaNacimiento;
        cout << "Ingrese matricula: ";
        i >> e.matricula;
        cout << "Ingrese cantidad de materias: ";
        i >> e.cantMaterias;
        for(int j = 0; j < e.cantMaterias; j++) {
            i >> e.materias[j];
        }
        return i;
    }
    friend ostream &operator << (ostream &o, Estudiante &e) {
        o << "CI: " << e.ci << endl;
        o << "Nombre: " << e.nombre << endl;
        o << "Carrera: " << e.carrera << endl;
        o << "Fecha de nacimiento: " << e.fechaNacimiento << endl;
        o << "Matricula: " << e.matricula << endl;
        o << "Materias: " << endl;
        for(int i = 0; i < e.cantMaterias; i++) {
            o << e.materias[i];
        }
        return o;
    }

};

#endif // ESTUDIANTE_H_INCLUDED
