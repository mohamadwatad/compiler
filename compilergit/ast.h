#pragma once

/**************************************
 *
 * University of Haifa
 *
 * Theory of compilation
 *
 * P machine compiler - code generation project

 **************************************/
 /*   PROGRAM = 258,
      BBEGIN = 259,
      END = 260,
      DECLARE = 261,
      PROCEDURE = 262,
      FUNCTION = 263,
      LABEL = 264,
      INTEGER = 265,
      REAL = 266,
      RECORD = 267,
      BOOLEAN = 268,
      ARRAY = 269,
      OF = 270,
      ASSIGN = 271,
      LC = 272,
      RC = 273,
      IF = 274,
      THEN = 275,
      ELSE = 276,
      WHILE = 277,
      REPEAT = 278,
      FI = 279,
      DO = 280,
      OD = 281,
      READ = 282,
      WRITE = 283,
      TRUE = 284,
      FALSE = 285,
      ADD = 286,
      MIN = 287,
      MUL = 288,
      DIV = 289,
      GOTO = 290,
      MOD = 291,
      LES = 292,
      LEQ = 293,
      EQU = 294,
      NEQ = 295,
      GRE = 296,
      GEQ = 297,
      AND = 298,
      OR = 299,
      NOT = 300,
      CASE = 301,
      FOR = 302,
      FIN = 303,
      IDENTICAL = 304,
      FROM = 305,
      BY = 306,
      TO = 307,
      NEW = 308,
      INTCONST = 309,
      IDE = 310,
      REALCONST = 311,
      STRING = 312,
      DUMMY = 313*/

#ifndef AST_H 
#define AST_H

#include <iostream>
#include <assert.h>
#include <string>
#include <iomanip>
using namespace std;

static int addressbeg = 5; //variable adress counter start from 5
static int Varsize = 1;//size of the variable in the symbol table


typedef struct dimensions {
    int li;
    int ui;
    int di;
    dimensions* next;
} Dimensions;


typedef struct spec_array {
    int subpart;
    string* name;
    int array_adress;
    int array_sizetype;
    int size;
    int space=0;
    int counter_dim = 0;
    int father_adress = 0;
    bool value_ref = 0;
    string* my_func_name = NULL;
    string* sizetype_name =NULL;
    spec_array* next = NULL;
    dimensions* start;
} Spec_array;


typedef struct variable {//our symbol table linked list
    string* name;
    int address;
    int size;
    int space;
    int size_point = 1;
    bool value_ref = 0;
    string* my_func_name = NULL;
   


    string* sizetype_name=NULL;
    spec_array* points;
    variable* next;
} Variable;

typedef struct record {
    string* name;
    int address;
    int size;
    string* my_func_name = NULL;
    string* sizetype_name = NULL;//
    int size_point = 1;
    int space;
    bool value_ref = 0;
    spec_array* arr = NULL;
    record* next;
} Record;


typedef struct Para_list {
    string* name;
    int size;
    bool by_ref = false;
    Para_list* next;
}paralist;




typedef struct func {
    string* name;
    string* name_of_dad=NULL;
    string* my_func = NULL;
    //int address;
    int ssp=5;
    int sep = 50;
    string* sizetype_name = NULL;//
    int depth = 0;
    int size = 2;
    int para_size = 0;
    Para_list* here = NULL;
    int address = 0;
    //int stat_link = 0;
    bool return_value = 0;//1 for func and 0 for proc
    bool value_ref = 0;
    bool as_para = false;//if func is a parametr or no
    func* next;
} Func;



static paralist* head_para = NULL;
static paralist* tail_para = NULL;
static paralist* this_para = NULL;
static Variable* first = NULL; //begining of the list
static Variable* last = NULL; //end of the list- importent to know were to add the new item
static Record* head = NULL; //begining of the list
static Record* tail = NULL; //end of the list- importent to know were to add the new item
static dimensions* head_dim = NULL; //begining of the list
static dimensions* tail_dim = NULL; //end of the list- importent to know were to add the new item
static Spec_array* head_Spec_array = NULL; //begining of the list
static Spec_array* tail_Spec_array = NULL; //end of the list- importent to know were to add the new item
static Dimensions* start_of_dim = NULL;
static Func* head_Func = NULL; //begining of the list
static Func* tail_Func = NULL; //end of the list- importent to know were to add the new item




static string* name_for_arrref = NULL;
static int how_many_dim = 1;

static bool in_ide = false; //flag for going to idetype class
static bool flag_ind = true; // flag to when to print ind
static bool flag_inc = false; // flag to when to print inc
static bool flag_dec = false; // flag to when to print dec
static bool in_const_for_inc = false; // flag to when if we entered intconst or realconst
static bool in_const_for_dec = false; // flag to when if we entered intconst or realconst
static int if_counter = 0; // counter for the if conditions
static int global_if_counter = 0;// counter for the if conditions
static int while_counter = 0;// counter for the while conditions
static int global_while_counter = 0;// counter for the while conditions
static int switch_counter = 0;// counter for the switch conditions
static int global_switch_counter = 0;// counter for the switch conditions
static int case_counter = 0;// counter for the case in switch conditions
static int op_code_num = 0; // checks if we in 286 or 287 which is inc/dec or add/sub
static bool op_inc_dec_flag = false;// flag if we in 286 or 287 which and need inc/dec 

static int just_once = 1;
static int add_of_rec = addressbeg;
static int record_size = 0;
static bool in_recordtype = false;
static bool in_recordlist = false;
static bool doing_record = false;
static int inc_value = 0;
static int  global_inc = 0;
static bool in_recordref = false;
static bool in_adresstype = false;
static int pointer_size = 1;
static bool in_arraytype = false;
static int last_record_label_add = 5;
static int in_var_dec = false;
static int arraysize = 1;
static Dimensions* the_dimension_start = NULL;
static int SUM_OF_DI = 1;
static bool in_variable = false;
static bool in_arrayref = false;
static int counter_for_dims = 0;
static bool flag_from_st = false;
static bool flag_from_arrayvariable = false;
static bool flag_array_rec = false;
static int temp_array_place = 0;
static int temp_subpart_place = 0;
static int dim_num = 0;
static int the_type_of_array = 1;
static bool flag_found_dad = false;
static string* missing_dad;
static bool in_newstatement = false;
static int the_new_size = 1;
static bool in_simpletype = false;
static string* the_name_of_sizetype =NULL;
static bool in_adressref = false;
static string* universal_name = NULL;
static bool found_my_clone = false;
static bool flag_clone_array = false;
static bool found = false;
static bool flag_in_st_no_arr = false;
static bool flag_in_records = false;
static bool  found_the_point = false;
static bool flag_try = false;
static string* the_name_for_new = NULL;
static string* the_name_for_new_points_to = NULL;
static bool flag_print_new = false;
static int par_size = 0;
static int dep = 0;
static int global_stat_link = 0;

static string* dad_name = NULL;
static string* this_dad_name = NULL;
static bool by_ref = false;
static bool in_funcdec = false;
static bool in_prodcdec = false;
static bool flag_for_printthings = 1;
static bool in_program = false;
static bool the_end = false;
static string* this_name_of_func = NULL;
static bool flag_for_func_prod = false;
static int ssp = 5;
static bool in_parametr = false;
static int flag_my_func_is_parametr = false;
static int global_size_for_parametrs = 0;
static string* the_func_we_calling = NULL;
static Para_list* global_start_of_para_to_check = NULL;
static int just_one_time = 1;
static bool in_assign = false;
static bool in_paramlist = false;
static bool in_procedstate = false;
static int global_size_for_smp = 0;
static bool flag_need_movs = false;
static int print_movs_size = 2;
static bool we_came_from_addition_to_address = false;
static int  size_to_add_to_address = 0;
/**
 * classes
 */
 // base class for tree nodes
class Object {
public:
    virtual void print(ostream& os) = 0;
    virtual void pcodegen(ostream& os) = 0;
    virtual Object* clone() const { return NULL; }
    virtual ~Object() {}
};

class Expr : public Object {
public:
    // Unary operations
    Expr(int op, Object* atom) : op_(op), atom_(atom), left_(NULL), right_(NULL), unary_(true) {}
    // Binary operations
    Expr(int op, Object* left, Object* right) : op_(op), left_(left), right_(right), atom_(NULL), unary_(false) {}

    Expr(const Expr& exp) {
        unary_ = exp.unary_;
        op_ = exp.op_;
        left_ = exp.left_->clone();
        right_ = exp.right_->clone();
        atom_ = exp.atom_->clone();
    }

    virtual ~Expr() {
        if (left_) delete left_;
        if (right_) delete right_;
        if (atom_) delete atom_;
    }


    void print(ostream& os) {
        os << "Node name : Expr" << endl;
        assert(op_);
        if (unary_) {
            os << "Unary op is : " << op_;
            assert(atom_);
            atom_->print(os);
        }
        else {
            os << "Binary op is : " << op_;
            assert(left_ && right_);
            right_->print(os);
            left_->print(os);
            
            
        }
    }
    void pcodegen(ostream& os) {
        assert(op_);
        op_inc_dec_flag = true;
       //x++,++x
        if (unary_) {
            assert(atom_);
            atom_->pcodegen(os);
            if (op_ == 287)
                os << "neg" << endl;
            else if (op_ == 300)
                os << "not" << endl;

        }
        else {
            int curr_op_num = op_code_num;
            bool temp_op_inc_dec_flag = op_inc_dec_flag;
            int temp_in_ide= in_ide;
            int temp_flag_ind = flag_ind;
            if (in_ide) {//to see if need to ind when printing if we had a variable and went to idetype
                flag_ind = true;
                in_ide = false;
            }
            assert(left_ && right_);

            right_->pcodegen(os);

           
            flag_ind = true;
            op_code_num = op_;
            in_const_for_inc = false;
            in_const_for_dec = false;
            op_inc_dec_flag = false;
            int temp_flag_inc = flag_inc;
            int temp_flag_dec = flag_dec;
            int temp_in_const_for_inc = in_const_for_inc;
            int temp_in_const_for_dec = in_const_for_dec;
            int temp1 = flag_try;
            flag_try = 0;
            left_->pcodegen(os);
            flag_try = temp1;
            flag_ind = temp_flag_ind;
            //now we check if we had a number or variable from the right side of the operation
            op_inc_dec_flag = temp_op_inc_dec_flag;
            if (in_const_for_inc) {
                flag_inc = true;
                in_const_for_inc = false;
            }
            if (in_const_for_dec) {
                //os << "rrr" << endl;
                flag_dec = true;
                in_const_for_dec = false;
            }
            if (op_ == 286)
            {
                if (flag_inc==0) // we dont need increment
                {
                    os << "add" << endl;
                    flag_try = false;
                    
                }
                
            }
            else if (op_ == 287) {
               // os << "here" << endl;
                if (flag_dec==0) {
                    os << "sub" << endl;
                    flag_try= false;
                }
                
            }
               
            else if (op_ == 288)
                os << "mul" << endl;
            else if (op_ == 289)
                os << "div" << endl;
            else if (op_ == 292)
                os << "les" << endl;
            else if (op_ == 293)
                os << "leq" << endl;
            else if (op_ == 294)
                os << "equ" << endl;
            else if (op_ == 295)
                os << "neq" << endl;
            else if (op_ == 296)
                os << "grt" << endl;
            else if (op_ == 297)
                os << "geq" << endl;
            else if (op_ == 298)
                os << "and" << endl;
            else if (op_ == 299)
                os << "or" << endl;
           
            flag_inc = temp_flag_inc;
            flag_dec = temp_flag_dec;
            in_const_for_inc = temp_in_const_for_inc;
            in_const_for_dec= temp_in_const_for_dec;
            in_ide = temp_in_ide;
            flag_ind = temp_flag_ind;
        }
        flag_try = false;
    }
    virtual Object* clone() const { return new Expr(*this); }

private:
    bool unary_;
    int op_;
    Object* left_;
    Object* right_;
    Object* atom_;
};

class ExprList : public Object {
public:
    ExprList(Object* expr) : expr_(expr), expr_list_(NULL) { assert(expr_); }
    ExprList(Object* expr, Object* expr_list) : expr_(expr), expr_list_(expr_list) { assert(expr_ && expr_list_); }

    ExprList(const ExprList& exp) {
        expr_ = exp.expr_->clone();
        expr_list_ = exp.expr_list_->clone();
    }

    virtual ~ExprList() {
        if (expr_) delete expr_;
        if (expr_list_) delete expr_list_;
    }

    void print(ostream& os) {
        os << "Node name : ExprList";
        assert(expr_);
        expr_->print(os);
        if (expr_list_) {
            expr_list_->print(os);
        }
    }
    void pcodegen(ostream& os) {
        assert(expr_);
        
        int temp = flag_ind;
        if (just_one_time>0) {
            Func* current4 = head_Func; // Initialize current.
            while (current4 != NULL) {
                if (*(current4->name) == *the_func_we_calling) {
                    
                    global_start_of_para_to_check = current4->here;
                    just_one_time--;

                }
                current4 = current4->next;
            }
        }
        if (global_start_of_para_to_check) {
            if (global_start_of_para_to_check->by_ref || global_start_of_para_to_check->size > 1) {
                flag_ind = false;
                if (global_start_of_para_to_check->size > 1) {
                    flag_need_movs = true;
                }
                else {
                    flag_need_movs = false;
                }
                
            }
            else {
                flag_ind = true;
                
            }
            global_start_of_para_to_check = global_start_of_para_to_check->next;
        }
        
        
        expr_->pcodegen(os);
        
        flag_ind = temp;
        if(flag_need_movs)
            os << "movs " << print_movs_size << endl;
        flag_need_movs = false;
        if (expr_list_) {
            expr_list_->pcodegen(os);
        }
        
    }
    virtual Object* clone() const { return new ExprList(*this); }

private:
    Object* expr_;
    Object* expr_list_;
};

class Dim : public Object {
public:
    Dim(Object* exp) : exp_(exp), dim_(NULL) { assert(exp_); }
    Dim(Object* exp, Object* dim) : exp_(exp), dim_(dim) { assert(exp_ && dim_); }

    Dim(const Dim& d) {
        exp_ = d.exp_->clone();
        dim_ = d.dim_->clone();
    }

    virtual ~Dim() {
        if (exp_) delete exp_;
        if (dim_) delete dim_;
    }

    void print(ostream& os) {
        os << "Node name : Dim" << endl;
        assert(exp_);
       
        

        exp_->print(os);

        
        
        
        if (dim_) {
            dim_->print(os);
        }
    }
    void pcodegen(ostream& os) {
        assert(exp_);
        Dimensions* temp1= start_of_dim;
        dim_num++;

        int temp_ind = flag_ind;
        flag_ind = true;
        
        int temp_flag_try = flag_try;
        flag_try = 1;


        int curr_op_num = op_code_num;
        bool temp_op_inc_dec_flag = op_inc_dec_flag;
        int temp_in_const_for_inc = in_const_for_inc;
        int temp_in_const_for_dec = in_const_for_dec;
        op_code_num = 0;
        op_inc_dec_flag = false;
        in_const_for_inc = false;
        in_const_for_dec = false;
      

        exp_->pcodegen(os);

        op_code_num= curr_op_num  ;
        op_inc_dec_flag =temp_op_inc_dec_flag  ;
        in_const_for_inc = temp_in_const_for_inc  ;
        in_const_for_dec= temp_in_const_for_dec  ;






      
        flag_try = temp_flag_try;

        flag_ind = temp_ind;

        int ixa = 1;
        
        if (temp1 == NULL) {
            
        }
        if (how_many_dim > dim_num) {
           
            for (temp1; temp1 != NULL; temp1=temp1->next) {
                ixa *= temp1->di;
               
            }
            ixa *= the_type_of_array;
            os << "ixa " << ixa << endl;
           
            
        }
        else if (how_many_dim == dim_num) {
            ixa = the_type_of_array;
            os << "ixa " << ixa << endl;
            os << "dec " << temp_subpart_place << endl;
           
            Spec_array* current1 = head_Spec_array;
            while (current1 != NULL) {
                if (name_for_arrref != NULL && *name_for_arrref == *(current1->name))
                {
                   
                    start_of_dim = current1->start;
                    
                    dim_num = 0;
                    if(current1->sizetype_name!=NULL)
                        name_for_arrref = current1->sizetype_name;
                  
                  
                    the_type_of_array = current1->array_sizetype;
                  
                    how_many_dim = current1->counter_dim;
                   
                    temp_subpart_place = current1->subpart;
                   
                }
                current1=current1->next;
            }
        }

        if(start_of_dim->next!=NULL)
            start_of_dim = start_of_dim->next;
       
        
        if (dim_) {
           
            dim_->pcodegen(os);
        }
    }
    virtual Object* clone() const { return new Dim(*this); }

private:
    Object* exp_;
    Object* dim_;
};

class Atom : public Object {
};

class IntConst : public Atom {
public:
    IntConst(const int i) : i_(i) {
    }
    IntConst(const IntConst& in) : i_(in.i_) {}

    void print(ostream& os) {
        os << "Node name : IntConst. Value is :" << i_ << endl;
    }
    void pcodegen(ostream& os) {
        
       
            if (op_code_num == 286 && op_inc_dec_flag == false && flag_try==0) {// if we need inc operation 
             
                in_const_for_inc = true;
                os << "inc " << i_ << endl;
              
                op_code_num = 0;
            }
            else if (op_code_num == 287 && op_inc_dec_flag == false && flag_try==0) {// if we need dec operation 
                in_const_for_dec = true;
                
                os << "dec " << i_ << endl;
               
                op_code_num = 0;
            }
            else {
                os << "ldc " << i_ << endl;
            }
       
    }
    virtual Object* clone() const { return new IntConst(*this); }

private:
    const int i_;
};

class RealConst : public Atom {
public:
    RealConst(const double r) : r_(r) {
    }
    RealConst(const RealConst& in) : r_(in.r_) {}

    void print(ostream& os) {
        os << "Node name : RealConst. Value is :" << r_ << endl;
    }
    void pcodegen(ostream& os) {
        if (op_code_num == 286 && op_inc_dec_flag == false && flag_try == 0) { // if we need inc operation 
            in_const_for_inc = true;
            os << "inc " << std::fixed << std::setprecision(1) << r_ << endl;
            op_code_num = 0;
        }
        else if (op_code_num == 287 && op_inc_dec_flag == false && flag_try == 0) {// if we need dec operation
            in_const_for_dec = true;
            os << "dec " << std::fixed << std::setprecision(1) << r_ << endl;
           
            op_code_num = 0;
        }
        else {
            os << "ldc " << std::fixed << std::setprecision(1) << r_ << endl;
            
        }
        
    }
    virtual Object* clone() const { return new RealConst(*this); }

private:
    const double r_;
};

class True : public Atom {
public:
    void print(ostream& os) {
        os << "Node name : trueConst. Value is true" << endl;
    }
    void pcodegen(ostream& os) {
        os << "ldc 1" << endl;
    }
    virtual Object* clone() const { return new True(); }

};

class False : public Atom {
public:
    void print(ostream& os) {
        os << "Node name : trueConst. Value is false" << endl;
    }
    void pcodegen(ostream& os) {
        os << "ldc 0" << endl;
    }
    virtual Object* clone() const { return new False(); }
};

class Var : public Atom {
};

class ArrayRef : public Var {
public:
    ArrayRef(Object* var, Object* dim) : var_(var), dim_(dim) { assert(var_ && dim_); }
    ArrayRef(const ArrayRef& arr) {
        var_ = arr.var_->clone();
        dim_ = arr.dim_->clone();
    }

    virtual ~ArrayRef() {
        if (var_) delete var_;
        if (dim_) delete dim_;
    }

    void print(ostream& os) {
        os << "Node name : ArrayRef" << endl;
        assert(var_ && dim_);
        var_->print(os);
      
        dim_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(var_ && dim_);
        in_arrayref = true;
        name_for_arrref = NULL;

        flag_try = true;

        int temp_ind = flag_ind;
        flag_ind = false;
        var_->pcodegen(os);

        flag_ind = temp_ind;
        int temp1 = temp_array_place;
       
        dim_num = 0;
       
        in_arrayref = false;
        if(start_of_dim->next!=NULL)
            start_of_dim=start_of_dim->next;
       
        dim_->pcodegen(os);
        if (flag_ind) {
            os << "ind" << endl;
            
        }
       
    }
    virtual Object* clone() const { return new ArrayRef(*this); }

private:
    Object* var_;
    Object* dim_;
};

class RecordRef : public Var {
public:
    RecordRef(Object* varExt, Object* varIn) : varExt_(varExt), varIn_(varIn) { assert(varExt_ && varIn_); }
    RecordRef(const RecordRef& rec) {
        varExt_ = rec.varExt_->clone();
        varIn_ = rec.varIn_->clone();
    }

    virtual ~RecordRef() {
        if (varExt_) delete varExt_;
        if (varIn_) delete varIn_;
    }

    void print(ostream& os) {
        os << "Node name : RecordRef" << endl;
        assert(varExt_ && varIn_);
        varExt_->print(os);
        varIn_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(varExt_ && varIn_);
      
        int temp_flag_ind = flag_ind;
        flag_ind = false;
        varExt_->pcodegen(os);
        flag_ind = temp_flag_ind;


        in_recordref = true;
      
        varIn_->pcodegen(os);
       
        in_recordref = false;
    }
    virtual Object* clone() const { return new RecordRef(*this); }

private:
    Object* varExt_;
    Object* varIn_;
};

class AddressRef : public Var {
public:
    AddressRef(Object* var) : var_(var) { assert(var_); }
    AddressRef(const AddressRef& addre) {
        var_ = addre.var_->clone();
    }

    virtual ~AddressRef() {
        if (var_) delete var_;
    }

    void print(ostream& os) {
        os << "Node name : AddressRef" << endl;
        assert(var_);
        var_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(var_);
        in_adressref = true;
        var_->pcodegen(os);
        
        in_adressref = false;
        os << "ind" << endl;

        if (flag_print_new && the_name_for_new_points_to!=NULL) {////
            
            the_name_for_new = the_name_for_new_points_to;///
            Variable* current300 = first; // Initialize current.
            while (current300 != NULL) {
                if (*(current300->name) == *the_name_for_new) {
                    the_new_size = current300->size_point;
                    the_name_for_new_points_to = current300->sizetype_name;
                }
                current300 = current300->next;
            }
            Record* current301 = head; // Initialize current.
            while (current301 != NULL) {
                if (*(current301->name) == *the_name_for_new) {
                    the_new_size = current301->size_point;
                   
                    the_name_for_new_points_to = current301->sizetype_name;
                }
                current301 = current301->next;
            }


        }///


    }
    virtual Object* clone() { return new AddressRef(*this); }

private:
    Object* var_;
};

class Statement : public Object {
};

class NewStatement : public Statement {
public:
    NewStatement(Object* var) : var_(var) { assert(var_); }
    NewStatement(const NewStatement& ns) {
        var_ = ns.var_->clone();
    }

    virtual ~NewStatement() {
        if (var_) delete var_;
    }

    void print(ostream& os) {
        os << "Node name : NewStatement";
        assert(var_);
        var_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(var_);
        in_newstatement = true;
        int temp_ind = flag_ind;
        flag_ind = false;

       int temp = flag_print_new;///
       flag_print_new = true;///

        var_->pcodegen(os);
      

       flag_ind = temp_ind;/////
        
        in_newstatement = false;
       
        
        the_new_size = 1;
       
        if (flag_print_new) {/////
            //find the size we point to
            //print ldc here
            Variable* current300 = first; // Initialize current.
            while (current300 != NULL) {
                if (*(current300->name) == *the_name_for_new) {
                    the_new_size = current300->size_point;
                    
                    if(current300->sizetype_name)
                       
                        the_name_for_new_points_to = current300->sizetype_name;
                }
                current300 = current300->next;
            }
            Record* current301 = head; // Initialize current.
            while (current301 != NULL) {
                if (*(current301->name) == *the_name_for_new) {
                    the_new_size = current301->size_point;
                    
                    if (current301->sizetype_name)
                       
                    the_name_for_new_points_to = current301->sizetype_name;
                }
                current301 = current301->next;
            }
            os << "ldc " << the_new_size << endl;////
            the_new_size = 1;///
        }
        os << "new" << endl;////
        flag_print_new = temp;/////
           ////
       
    }
    virtual Object* clone() { return new NewStatement(*this); }

private:
    Object* var_;
};

class WriteStrStatement : public Statement {
public:
    WriteStrStatement(const char* str) {
        str_ = new string(str);
    }

    WriteStrStatement(const WriteStrStatement& ns) {
        str_ = new string(*ns.str_);
    }

    virtual ~WriteStrStatement() {
        if (str_) delete str_;
    }
    void print(ostream& os) {
        os << "Node name : WriteStrStatement";
        assert(str_);
        os << "Str statement is: " << str_ << endl;
    }
    void pcodegen(ostream& os) {
        assert(str_);
    }
    virtual Object* clone() { return new WriteStrStatement(*this); }

private:
    string* str_;
};

class WriteVarStatement : public Statement {
public:
    WriteVarStatement(Object* exp) : exp_(exp) { assert(exp_); }

    WriteVarStatement(const WriteVarStatement& ex) {
        exp_ = ex.clone();
    }

    virtual ~WriteVarStatement() {
        if (exp_) delete exp_;
    }

    void print(ostream& os) {
        os << "Node name : WriteVarStatement";
        assert(exp_);
        exp_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(exp_);
        exp_->pcodegen(os);
        os << "print" << endl;
    }
    virtual Object* clone() const { return new WriteVarStatement(*this); }

private:
    Object* exp_;
};

class ProcedureStatement : public Statement {
public:
    ProcedureStatement(const char* str) {
        str_ = new string(str);
    }

    ProcedureStatement(Object* expr_list, const char* str) : expr_list_(expr_list) {
        assert(expr_list_);
        str_ = new string(str);
    }

    ProcedureStatement(const ProcedureStatement& ps) {
        expr_list_ = ps.expr_list_->clone();
        str_ = new string(*ps.str_);
    }

    virtual ~ProcedureStatement() {
        if (str_) delete str_;
        if (expr_list_) delete expr_list_;
    }

    void print(ostream& os) {
        os << "Node name : ProcedureStatement. Proc name : " << str_ << endl;
        if (expr_list_) {
            expr_list_->print(os);
        }
    }
    void pcodegen(ostream& os) {
        //mst mstf 
       
      
        the_func_we_calling = str_;
        int my_dep, other_dep, temp_para_size_for_cup, temp_address, temporary, my_dad_linked;
        bool we_need_mstf = false;
        string* temp_name = NULL;
        Func* temp = head_Func;
        while (temp != NULL) {
            if (*(temp->name) == *str_) {
                
                temp_address = temp->address;
                temp_para_size_for_cup = temp->para_size;
                my_dad_linked = (temp->depth) - 1;
                
                if (temp->as_para) {
                    
                    os << "mstf ";
                    we_need_mstf = true;
                    temp_name= temp->my_func;
                    Func* user2 = head_Func;
                    while (user2) {
                        if (*(user2->name) == *temp_name) {
                            
                            my_dep = user2->depth;
                            temp_para_size_for_cup = user2->para_size;
                        }
                        user2 = user2->next;
                    }
                }
                else {
                    os << "mst ";

                    Func* user2 = head_Func;
                    while (user2) {
                        if (*(user2->name) == *this_name_of_func) {
                           
                            my_dep = user2->depth;
                            
                        }
                        user2 = user2->next;
                    }
                    
                }
               
            }
            if (*(temp->name) == *this_name_of_func) {//call from func in i
                
                other_dep = temp->depth;
                temporary = temp->depth;
            }
            temp = temp->next;
        }
       
        if (!we_need_mstf) {
            os << abs(my_dad_linked-other_dep)  << endl;
        }
        if (we_need_mstf) {
            
            
            os <<abs(temporary-my_dep)<<" "<< temp_address << endl;
           
        }
        just_one_time = 1;
        
        in_procedstate = true;
        if (expr_list_) {
            expr_list_->pcodegen(os);
        }
        
        in_procedstate = false;
         
       if (!we_need_mstf)
            os << "cup " << temp_para_size_for_cup << " " << *str_ << endl;
        else {
            os << "smp " << global_size_for_smp << endl;
           
            os << "cupi " << abs(temporary - my_dep) <<" "<< temp_address << endl;
            we_need_mstf = false;
        }
       global_size_for_smp = 0;
       
    }
    virtual Object* clone() const { return new ProcedureStatement(*this); }

private:
    Object* expr_list_;
    string* str_;
};

class Case : public Object {
public:
    Case(Object* stat_list, int val) : leafChild_(NULL), stat_list_(stat_list) {
        // note the special treatment in miny.y for this case (makenode)
        leafChild_ = new IntConst(val);
        assert(stat_list_);
    }

    Case(const Case& c) {
        stat_list_ = c.stat_list_->clone();
        leafChild_ = c.leafChild_->clone();
    }

    virtual ~Case() {
        if (stat_list_) delete stat_list_;
        if (leafChild_) delete leafChild_;
    }

    void print(ostream& os) {
        os << "Node name : Case";
        assert(stat_list_);
        stat_list_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(stat_list_);
        stat_list_->pcodegen(os);
        
    }
    virtual Object* clone() const { return new Case(*this); }

private:
    Object* stat_list_;
    Object* leafChild_;
};


class CaseList : public Object {
public:
    CaseList(Object* ccase) : case_(ccase), case_list_(NULL) { assert(case_); }
    CaseList(Object* ccase, Object* case_list) : case_(ccase), case_list_(case_list) { assert(case_ && case_list_); }

    CaseList(const CaseList& cl) {
        case_ = cl.case_->clone();
        case_list_ = cl.case_list_->clone();
    }

    virtual ~CaseList() {
        if (case_) delete case_;
        if (case_list_) delete case_list_;
    }

    void print(ostream& os) {
        os << "Node name : CaseList";
        assert(case_);
        case_->print(os);
        if (case_list_) {
            case_list_->print(os);
        }
    }
    void pcodegen(ostream& os) {
        assert(case_);
       
        case_counter++; 
        int counter_for_case = case_counter;//local counter to save the value in each stage while recurisve for case
        int which_switch = global_switch_counter;//local counter to save the value in each stage while recurisve for the switch 

        os << "case_" << case_counter << "_" << global_switch_counter << ":" << endl;
       ;
        case_->pcodegen(os);

       
        os << "ujp end_switch_" << which_switch << endl;

        global_switch_counter = which_switch;
        if (case_list_) {
           
            case_list_->pcodegen(os);
           
           
        }
        os << "ujp case_" << counter_for_case <<"_"<< which_switch << endl;
        
    }
    virtual Object* clone() const { return new CaseList(*this); }

private:
    Object* case_;
    Object* case_list_;
};

class CaseStatement : public Statement {
public:
    CaseStatement(Object* exp, Object* case_list) : exp_(exp), case_list_(case_list) { assert(exp_ && case_list_); }

    CaseStatement(const CaseStatement& cs) {
        exp_ = cs.exp_->clone();
        case_list_ = cs.case_list_->clone();
    }

    virtual ~CaseStatement() {
        if (exp_) delete exp_;
        if (case_list_) delete case_list_;
    }

    void print(ostream& os) {
        os << "Node name : CaseStatement";
        assert(exp_ && case_list_);
        exp_->print(os);//switch exp
        case_list_->print(os);//in the switch
    }
    void pcodegen(ostream& os) {
        assert(exp_ && case_list_);

        switch_counter++;
       
       
        int counter_for_switch = switch_counter;//local counter to save the switch number we in
        global_switch_counter = switch_counter;//gloabl counter to return the value for our counter in the end
        int which_case = case_counter;//local counter for the case in switch
        case_counter = 0;
        int temp_flag_for_ind = flag_ind;
        flag_ind = 1;
        exp_->pcodegen(os);
        flag_ind = temp_flag_for_ind;
        os << "neg" << endl;
        os << "ixj end_switch_" << switch_counter << endl;

        
        case_list_->pcodegen(os);
       
        os << "end_switch_" << counter_for_switch << ":" << endl;
       
        case_counter = which_case;
    }
    virtual Object* clone() const { return new CaseStatement(*this); }

private:
    Object* exp_;
    Object* case_list_;
};

class LoopStatement : public Statement {
public:
    LoopStatement(Object* exp, Object* stat_list) : exp_(exp), stat_list_(stat_list) { assert(exp_ && stat_list_); }

    LoopStatement(const LoopStatement& ls) {
        exp_ = ls.exp_->clone();
        stat_list_ = ls.stat_list_->clone();
    }

    virtual ~LoopStatement() {
        if (exp_) delete exp_;
        if (stat_list_) delete stat_list_;
    }

    void print(ostream& os) {
        os << "Node name : LoopStatement";
        assert(exp_ && stat_list_);
        exp_->print(os);
        stat_list_->print(os);
    }
    /*fgdsd*/
    void pcodegen(ostream& os) {
        assert(exp_ && stat_list_);
        int counter;
        while_counter++;//while number if we have more than one while
        global_while_counter = while_counter;//to return the number of our while in the end if we have more than one while in each other
      
        os << "loop_" << while_counter << ":" << endl;

        if (stat_list_) {
            int temp_flag_for_ind = flag_ind;
            flag_ind = 1;
            exp_->pcodegen(os);
            os << "fjp end_loop_" << while_counter << endl;
            flag_ind = temp_flag_for_ind;
            counter = while_counter;

            stat_list_->pcodegen(os);

            while_counter = counter;
            os << "ujp loop_" << while_counter << endl;
            os << "end_loop_" << while_counter <<":" << endl;
        }
        while_counter = global_while_counter;
        
    }
    virtual Object* clone() const { return new LoopStatement(*this); }

private:
    Object* exp_;
    Object* stat_list_;
};


class ConditionalStatement : public Statement {
public:
    ConditionalStatement(Object* exp, Object* stat_list_if) : exp_(exp), stat_list_if_(stat_list_if), stat_list_else_(NULL) { assert(exp_ && stat_list_if_); }
    ConditionalStatement(Object* exp, Object* stat_list_if, Object* stat_list_else) : exp_(exp), stat_list_if_(stat_list_if), stat_list_else_(stat_list_else) { assert(exp_ && stat_list_if_ && stat_list_else_); }

    ConditionalStatement(const ConditionalStatement& cs) {
        exp_ = cs.exp_->clone();
        stat_list_if_ = cs.stat_list_if_->clone();
        stat_list_else_ = cs.stat_list_else_->clone();
    }

    virtual ~ConditionalStatement() {
        if (exp_) delete exp_;
        if (stat_list_if_) delete stat_list_if_;
        if (stat_list_else_) delete stat_list_else_;
    }

    void print(ostream& os) {
        os << "Node name : ConditionalStatement";
        assert(exp_ && stat_list_if_);
        exp_->print(os);
        stat_list_if_->print(os);
        if (stat_list_else_) {
            stat_list_else_->print(os);
        }
    }
    void pcodegen(ostream& os) {
        assert(exp_ && stat_list_if_);
        if_counter++;
        global_if_counter = if_counter;
         int temp;
        
        if (stat_list_else_) {
            
            int temp_flag_for_ind = flag_ind;
            flag_ind = 1;
            exp_->pcodegen(os);
            flag_ind = temp_flag_for_ind;
            os << "fjp else_if_" << if_counter << endl;

            temp = if_counter;

            stat_list_if_->pcodegen(os);

            if_counter = temp;
            os << "ujp end_if_" << if_counter << endl;
            os << "else_if_"<< if_counter << ":" << endl;
           
            temp = if_counter;

            stat_list_else_->pcodegen(os);

            if_counter = temp;
            os <<"end_if_"<< if_counter  << ":" << endl;
           

        }
        else//no else just if
        {
            int temp_flag_for_ind = flag_ind;
            flag_ind = 1;
            exp_->pcodegen(os);
            os << "fjp end_if_" << if_counter << endl;
            flag_ind = temp_flag_for_ind;
            temp = if_counter;

            stat_list_if_->pcodegen(os);

            if_counter = temp;
            os <<"end_if_"<< if_counter << ":" << endl;
            
           
        }
        if_counter = global_if_counter;
    }
    virtual Object* clone() const { return new ConditionalStatement(*this); }

private:
    Object* exp_;
    Object* stat_list_if_;
    Object* stat_list_else_;
};


class Assign : public Statement {
public:
    Assign(Object* var, Object* exp) : var_(var), exp_(exp) { assert(var_ && exp_); }

    Assign(const Assign& as) {
        var_ = as.var_->clone();
        exp_ = as.exp_->clone();
    }

    virtual ~Assign() {
        if (exp_) delete exp_;
        if (var_) delete var_;
    }

    void print(ostream& os) {
        os << "Node name : Assign";
        assert(var_ && exp_);
        
        exp_->print(os);
       
        var_->print(os);//the right of =
       

    }
    void pcodegen(ostream& os) {
        assert(var_ && exp_);
        int temp_flag_ind = flag_ind;
        flag_ind = false;
        in_assign = true;
        
        exp_->pcodegen(os);
        in_assign = false;
        flag_ind = true;
       
        var_->pcodegen(os);
        
        flag_ind = temp_flag_ind;
        os << "sto" << endl;

    }
    virtual Object* clone() const { return new Assign(*this); }

private:
    Object* var_;
    Object* exp_;
};

class StatementList : public Object {
public:
    StatementList(Object* stat) : stat_list_(NULL), stat_(stat) { assert(stat_); }
    StatementList(Object* stat_list, Object* stat) : stat_list_(stat_list), stat_(stat) { assert(stat_list_ && stat); }

    StatementList(const StatementList& sl) {
        stat_ = sl.stat_->clone();
        stat_list_ = sl.stat_list_->clone();
    }

    virtual ~StatementList() {
        if (stat_) delete stat_;
        if (stat_list_) delete stat_list_;
    }

    void print(ostream& os) {
        os << "Node name : StatementList" << endl;
        if (stat_list_) {
            stat_list_->print(os);
        }
        assert(stat_);
        stat_->print(os);
    }
    void pcodegen(ostream& os) {
        if (stat_list_) {
            stat_list_->pcodegen(os);
        }
        assert(stat_);
        stat_->pcodegen(os);
    }
    virtual Object* clone() const { return new StatementList(*this); }

private:
    Object* stat_;
    Object* stat_list_;
};

class RecordList : public Object {
public:
    RecordList(Object* var_decl) : record_list_(NULL), var_decl_(var_decl) { 
        assert(var_decl_); 
        
    }
    RecordList(Object* record_list, Object* var_decl) : record_list_(record_list), var_decl_(var_decl) { assert(record_list_ && var_decl); }

    RecordList(const RecordList& li) {
        var_decl_ = li.var_decl_->clone();
        record_list_ = li.record_list_->clone();
    }

    virtual ~RecordList() {
        if (var_decl_) delete var_decl_;
        if (record_list_) delete record_list_;
    }

    void print(ostream& os) {
        os << "Node name : RecordList" << endl;
        if (record_list_) {
            record_list_->print(os);
        }
        assert(var_decl_);
        var_decl_->print(os);
    }
    void pcodegen(ostream& os) {
        in_recordlist = true;
        
        if (record_list_) {
            record_list_->pcodegen(os);
        }
        assert(var_decl_);
        var_decl_->pcodegen(os);
     
        in_recordlist = false;

    }
    virtual Object* clone() const { return new RecordList(*this); }

private:
    Object* var_decl_;
    Object* record_list_;
};

class Type : public Object {
};

class SimpleType : public Type {
public:
    SimpleType(const char* name) {
        name_ = new string(name);
        
    }

    virtual ~SimpleType() {
        if (name_)delete name_;
    }

    SimpleType(const SimpleType& s) {
        name_ = new string(*s.name_);
    }

    void print(ostream& os) {
        os << "Node name : SimpleType" << endl;;

        os << "Type is : " << (*name_) << endl;
    }
    void pcodegen(ostream& os) {
        in_simpletype = true;
        if (in_prodcdec) {
            par_size++;
        }
        if (in_recordlist && in_arraytype==0 && in_var_dec==1) {
            

            record_size++;
           
            Varsize=1;
        }
        
    }
    virtual Object* clone() const { return new SimpleType(*this); }

private:
    string* name_;
};

class IdeType : public Type {
public:
    IdeType(const char* name) {
        name_ = new string(name);
    }

    virtual ~IdeType() {
        if (name_) delete name_;
    }

    IdeType(const IdeType& s) {
        name_ = new string(*s.name_);
    }

    void print(ostream& os) {
        os << "Node name : IdeType the name : " <<*name_ << endl;
       
    }
    void pcodegen(ostream& os) {
        int add=0;//short for address
        int size = 0;
        int shift = 0;
        in_ide = true;//we reached a variable
       
        universal_name = name_;
        if (in_parametr) {
            
            Func* current4 = head_Func; // Initialize current.
            while (current4 != NULL) {
                
                if (*(current4->name) == *name_) {
                   
                    flag_my_func_is_parametr = true;
                    
                    
                }
                current4 = current4->next;
            }

        }
       
        if ((in_prodcdec || in_funcdec) && !by_ref) {
            //os << "hi2" << endl;
            Spec_array* current4 = head_Spec_array; // Initialize current.
            while (current4 != NULL) {
                if (*(current4->name) == *name_) {
                    par_size += current4->size;
                    

                }
                current4 = current4->next;
            }

           
                variable* current44 = first; // Initialize current.
                while (current44 != NULL) {
                    if (*(current44->name) == *name_) {
                        par_size += current44->size;
                       

                    }
                    current44 = current44->next;
                }
           
            
                Record* current441 = head; // Initialize current.
                while (current441 != NULL) {
                    if (*(current441->name) == *name_) {
                        par_size += current441->size;
                       

                    }
                    current441 = current441->next;
                }
            
        }

        
        if (in_var_dec && in_adresstype==0) {
            
            Spec_array* current4 = head_Spec_array; // Initialize current.
            while (current4 != NULL) {
                if (*(current4->name) == *name_) {
                   
                    flag_clone_array = true;
                    found = true;
                    universal_name = name_;
                    
                }
                current4 = current4->next;
            }
           
            if (!found) {
                variable* current44 = first; // Initialize current.
                while (current44 != NULL) {
                    if (*(current44->name) == *name_) {
                        we_came_from_addition_to_address = true;
                        flag_in_st_no_arr = true;
                        found = true;
                        universal_name = name_;
                        //os << "im here with " << *name_ << endl;
                        size_to_add_to_address = current44->size;
                        
                    }
                    current44 = current44->next;
                }
            }
            if (!found) {
               
                Record* current44 = head; // Initialize current.
                while (current44 != NULL) {
                    if (*(current44->name) == *name_) {
                        
                        flag_in_records = true;
                        found = true;
                        universal_name = name_;
                        
                        
                    }
                    current44 = current44->next;
                }
            }

            
            
            in_variable = false;
        }
        if (in_recordlist) 
        {
            if (in_arraytype && in_adresstype==0 ) {
                
                Variable* current1 = first; // Initialize current.
                while (current1 != NULL) {
                    if (*(current1->name) == *name_)
                    {
                        
                        size = current1->size;
                       
                    }

                    current1 = current1->next;
                }
                Record* current1997 = head; // Initialize current.
                while (current1997 != NULL) {
                    if (*(current1997->name) == *name_) {
                        size = current1997->size;
                       
                    }
                    current1997 = current1997->next;
                }

                Spec_array* current3010 = head_Spec_array;
                while (current3010 != NULL) {
                    if (*(current3010->name) == *name_) {
                        size = current3010->size;
                       
                    }
                    current3010 = current3010->next;
                }

              
            }
            else if(in_adresstype && in_arraytype==0) {
               
                record_size++;
                
            }
            else {
                Variable* current1 = first; // Initialize current.
                while (current1 != NULL) {
                    if (*(current1->name) == *name_)
                    {
                        
                        size = current1->size;
                        
                    }

                    current1 = current1->next;
                }
                Record* current1997 = head; // Initialize current.
                while (current1997 != NULL) {
                    if (*(current1997->name) == *name_) {
                        size = current1997->size;
                      
                    }
                    current1997 = current1997->next;
                }

                Spec_array* current3010 = head_Spec_array;
                while (current3010 != NULL) {
                    if (*(current3010->name) == *name_) {
                        size = current3010->size;
                      
                    }
                    current3010 = current3010->next;
                }
                
                record_size += size;
             
            }
            Varsize = 1;
            
            
        }
        if (in_adresstype) {
            Spec_array* current222 = head_Spec_array; // Initialize current.
            while (current222 != NULL) {
                if (*(current222->name) == *name_) {
                    size = current222->size;
                    flag_found_dad = true;
                    missing_dad = name_;
                    
                }
                current222 = current222->next;
            }
            pointer_size = size;
            
            if (flag_found_dad == false) {
                Variable* current2 = first; // Initialize current.
                while (current2 != NULL) {
                    if (*(current2->name) == *name_) {
                        size = current2->size;
                        flag_found_dad = true;
                        
                        missing_dad = name_;
                    }
                    current2 = current2->next;
                }
                pointer_size = size;
               
            }
            if (flag_found_dad == false) {
                Record* current2222 = head; // Initialize current.
                while (current2222 != NULL) {
                    if (*(current2222->name) == *name_) {
                        size = current2222->size;
                        flag_found_dad = true;
                        missing_dad = name_;
                       
                    }
                    current2222 = current2222->next;
                }
                pointer_size = size;
            }
            if (flag_found_dad == false) {
               
                pointer_size = -1;
               
            }

            
        }
        if (in_arraytype) {
            Variable* current3 = first; // Initialize current.
            while (current3 != NULL) {
                if (*(current3->name) == *name_) {
                    size = current3->size;
                   
                    the_name_of_sizetype = current3->name;
                }
                current3 = current3->next;
            }
            Spec_array* current3000 = head_Spec_array;
            while (current3000 != NULL) {
                if (*(current3000->name) == *name_) {
                    size = current3000->size;
                    
                    the_name_of_sizetype = current3000->name;
                }
                current3000 = current3000->next;
            }
            arraysize = size;
            

            
        }
        if (in_arrayref) {
            Spec_array* current7 = head_Spec_array;
            while (current7 != NULL) {
                if (*(current7->name) == *name_) {
                    found_the_point = true;
                   
                    temp_subpart_place = current7->subpart;
                    
                    start_of_dim = current7->start;
                    name_for_arrref = current7->sizetype_name;
                    how_many_dim = current7->counter_dim;
                    the_type_of_array = current7->array_sizetype;
                    
                }
                current7 = current7->next;
            }
            if (!found_the_point) {
                Variable* current77 = first;
                while (current77 != NULL) {
                    if (*(current77->name) == *name_) {
                        found_the_point = true;
                       
                        temp_subpart_place = current77->points->subpart;
                        
                        start_of_dim = current77->points->start;
                        name_for_arrref = current77->sizetype_name;
                        how_many_dim = current77->points->counter_dim;
                        the_type_of_array = current77->points->array_sizetype;
                        
                    }
                    current77 = current77->next;
                }
            }
            if (!found_the_point) {
                Record* current7777 = head;
                while (current7777 != NULL) {
                    if (*(current7777->name) == *name_) {
                        found_the_point = true;
                        
                        temp_subpart_place = current7777->arr->subpart;
                       
                        start_of_dim = current7777->arr->start;
                        name_for_arrref = current7777->arr->sizetype_name;
                        how_many_dim = current7777->arr->counter_dim;
                        the_type_of_array = current7777->arr->array_sizetype;
                        
                    }
                    current7777 = current7777->next;
                }
            }
            found_the_point = false;
        }
       
        if (in_newstatement) {
            Variable* current300 = first; // Initialize current.
            while (current300 != NULL) {
                if (*(current300->name) == *name_) {
                    the_new_size = current300->size_point;
                    the_name_for_new = name_;
                    the_name_for_new_points_to = current300->sizetype_name;
                }
                current300 = current300->next;
            }
            Record* current301 = head; // Initialize current.
            while (current301 != NULL) {
                if (*(current301->name) == *name_) {
                    the_new_size = current301->size_point;
                    the_name_for_new = name_;
                    the_name_for_new_points_to = current301->sizetype_name;
                }
                current301 = current301->next;
            }
            if (flag_print_new) {////
                
                the_name_for_new = name_;///
            }
        }
       
        //////////////////////////////////////////////////////////////////////////////////////////////////////////////
        bool another_ind = false;
        bool a_func = false;
        int movs_size = 0;
        int flag_need_ldcname = 0;
        int depth_of_me = 0;
        int depth_of_my_father = 0;
        string* which_depth = NULL;
        int  lin_st = 0;
      
            Record* current1 = head; // Initialize current.
            while (current1 != NULL) {
                if (*(current1->name) == *name_) {
                   
                    global_size_for_smp += current1->size;
                    movs_size = current1->size;
                    
                    add = current1->address;
                    if (current1->value_ref) {
                        another_ind = true;
                    }
                    
                    which_depth = current1->my_func_name;

                    
                }
                current1 = current1->next;
            }
           
            Variable* current2 = first; // Initialize current.
            while (current2 != NULL) {
                if (*(current2->name) == *name_) {
                   
                    movs_size = current2->size;
                    
                    global_size_for_smp += current2->size;
                   
                    add = current2->address;
                    if (current2->value_ref) {
                        another_ind = true;
                    }
                   
                    which_depth = current2->my_func_name;
                   
                }
                current2 = current2->next;
            }
            
            Spec_array* current3 = head_Spec_array; // Initialize current.
            while (current3 != NULL) {
                if (*(current3->name) == *name_) {
                    
                    global_size_for_smp += current3->size;
                    movs_size = current3->size;
                    
                    add = current3->array_adress;
                    if (current3->value_ref) {
                        another_ind = true;
                    }
                   
                    which_depth = current3->my_func_name;
                    
                }
                current3 = current3->next;
            }

           
            Func* current33 = head_Func; // Initialize current.
            while (current33 != NULL) {
                if (*(current33->name) == *name_) {
                    
                    global_size_for_smp += current33->size;
                    movs_size = 2;
                    flag_need_movs = current33->as_para;
                    flag_need_ldcname = current33->as_para;
                    a_func = true;
                    depth_of_my_father = current33->depth - 1;
                    
                    add = current33->address;
                    if (current33->value_ref) {
                        another_ind = true;
                    }
                    
                    if (current33->my_func) {
                        which_depth = current33->my_func;
                       
                    }
                  
                }
                current33 = current33->next;
            }
            
            Func* current4 = head_Func; // Initialize current.
            while (current4 != NULL) {
                

                if (current4->value_ref) {
                    another_ind = true;
                }
                
                if (which_depth) {
                    if (*(current4->name) == *which_depth) {
                       
                        lin_st = current4->depth;
                       
                    }
                }
                current4 = current4->next;
            }
           
            Func* current5 = head_Func; // to calculate lda link
            while (current5 != NULL) {
                
                if (*(current5->name) == *this_name_of_func) {
                   
                    depth_of_me = current5->depth;
                    lin_st -= current5->depth;
                    lin_st = abs(lin_st);
                    if (*this_name_of_func == *name_) {
                        lin_st = 0;
                        
                        global_size_for_smp += 2;
                        
                    }
                    
                }


                current5 = current5->next;
            }
        

       
        if (in_var_dec == 0 ) {
            
            if (in_recordref == 0) {
                
                
                if (in_procedstate && a_func && flag_need_ldcname==0) {
                   
                    os << "ldc " << *name_ << endl;
                    os << "lda "<<abs(depth_of_me-depth_of_my_father)<<" 0" << endl;
                    a_func = false;
                }
                else {
                    os << "lda " << lin_st << " " << add << endl;
                    if (another_ind) {
                        os << "ind" << endl;
                        another_ind = false;
                    }
                }

                if (flag_need_movs) {
                   
                    print_movs_size = movs_size;
                    
                }
                

            }
            
            else if (in_recordref) {
                Variable* current = first; // Initialize current.
                while (current != NULL) {
                    if (*(current->name) == *name_) {
                        add = current->address;
                        os << "lda _  " << add << endl;//lda and ind if needed
                        if (another_ind) {
                            os << "ind" << endl;
                            another_ind = false;
                        }
                    }
                    current = current->next;
                }
                Record* current1 = head; // Initialize current.
                while (current1 != NULL) {
                    if (*(current1->name) == *name_) {
                        add = current1->address;
                        
                        os << "inc " << current1->space << endl;
                    }
                    current1 = current1->next;
                }
                
            }


            else {
                
                Record* current3 = head; // Initialize current.
                while (current3 != NULL) {
                    if (*(current3->name) == *name_) {
                        shift = current3->space;
                        os << "inc " << shift << endl;
                        
                    }
                    current3 = current3->next;
                }
              
                

            }
            if (flag_ind) { // if we need ind
               
                os << "ind" << endl;
                
               
            }
        }
        
          
    }
    virtual Object* clone() const { return new IdeType(*this); }

private:
    string* name_;
};




class ArrayType : public Type {
public:
    ArrayType(int l, int u, Object* type) : low_(l), up_(u), type_(type) { assert(type_); }

    ArrayType(const ArrayType& a) : low_(a.low_), up_(a.up_) {
        type_ = a.type_->clone();
    }

    virtual ~ArrayType() {
        if (type_) delete type_;
    }

    void print(ostream& os) {
        os << "Node name : ArrayType: low bound is: " << low_ << ", up bound is: " << up_ << endl;
        assert(type_);
        //os << "BEFORE" << endl;
        type_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(type_);

        in_arraytype = true;
        if (in_recordlist) {
            flag_array_rec = true;
        }
        counter_for_dims++;
        Dimensions* temp1;
        temp1 = (Dimensions*)malloc(sizeof(Dimensions)); //dynamic allocation for the new item at the tab
        if (temp1 == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        temp1->li = low_;
        temp1->ui = up_;
        temp1->di = up_ - low_ + 1;
        SUM_OF_DI *= temp1->di;
        temp1->next = NULL;
        if (head_dim == NULL) { //list is empty

            head_dim = tail_dim = temp1;
        }
        else {
            tail_dim->next = temp1;
            tail_dim = temp1;
        }
        
        arraysize = 1;
        the_name_of_sizetype = NULL;
        the_dimension_start = head_dim;
      
        type_->pcodegen(os);
        tail_dim->next = NULL;
        tail_dim - NULL;
        head_dim = NULL;
       
    }
    virtual Object* clone() const { return new ArrayType(*this); }

private:
    Object* type_;
    int low_, up_;
};

class RecordType : public Type {
public:
    RecordType(Object* record_list) : record_list_(record_list) { 
      
    }

    RecordType(const RecordType& y) {
        record_list_ = y.record_list_->clone();
    }

    virtual ~RecordType() {
        if (record_list_) delete record_list_;
    }

    void print(ostream& os) {
        os << "Node name : RecordType" << endl;
        assert(record_list_);
        record_list_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(record_list_);
        in_recordtype = true;
        add_of_rec = addressbeg;
        last_record_label_add = addressbeg;
      
        record_size = 0;
        record_list_->pcodegen(os);

        
        
    }
    virtual Object* clone() const { return new RecordType(*this); }

private:
    Object* record_list_;
};


class AddressType : public Type {
public:
    AddressType(Object* type) : type_(type) { assert(type_); }

    AddressType(const AddressType& t) {
        type_ = t.type_->clone();
    }

    virtual ~AddressType() {
        if (type_) delete type_;
    }

    void print(ostream& os) {
        os << "Node name : AddressType" << endl;
        assert(type_);
        type_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(type_);
        in_adresstype = true;
        pointer_size = 1;
        
       
        type_->pcodegen(os);
      
    }
    virtual Object* clone() const { return new AddressType(*this); }

private:
    Object* type_;
};


class Declaration : public Object {
};


class VariableDeclaration : public Declaration {
public:
    VariableDeclaration(Object* type, const char* str) : type_(type) {
        assert(type_);
        name_ = new string(str);
        in_variable = true;
        /*add to symboltable*/
    }

    VariableDeclaration(const VariableDeclaration& p) {
        type_ = p.type_->clone();
        name_ = new string(*p.name_);
    }

    virtual ~VariableDeclaration() {
        if (type_) delete type_;
        delete name_;
    }

    void print(ostream& os) {
        os << "Node name : VariableDeclaration. Var name is: " << *name_ << endl;
        assert(type_);
        type_->print(os);
    }


    void pcodegen(ostream& os) {
        assert(type_);
        in_var_dec = true;
        
        type_->pcodegen(os);
        
        in_var_dec = false;
        Variable* temp1;
        if (in_recordlist == 0 || (in_adresstype==1 && in_recordlist==0)) {
            flag_from_st = true;
            
            temp1 = (Variable*)malloc(sizeof(Variable)); //dynamic allocation for the new item at the tab
            if (temp1 == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
            }
            temp1->name = name_;
            
            if (doing_record) {//was before
                temp1->address = add_of_rec;
                
                last_record_label_add = add_of_rec;
                doing_record = false;
            }
            else {
                temp1->address = addressbeg++;
                if (we_came_from_addition_to_address) {
                    we_came_from_addition_to_address = false;
                    addressbeg += size_to_add_to_address - 1;
                }
                ssp = addressbeg;

            }
            temp1->size = Varsize;
            if (in_adresstype==0 && in_arraytype==0 && in_simpletype==0) {
               
                temp1->size = record_size;
                
                    Record* current00 = head;
                    while (current00 != NULL) {
                        if (current00->size_point== -1)
                        {
                            current00->size_point = record_size;
                        }

                        current00 = current00->next;
                    }
                
            }
            
            if (in_adresstype) {
                temp1->size_point = pointer_size;
                if (missing_dad != NULL) {
                    
                    Variable* current2220 = first; // Initialize current.////
                    while (current2220 != NULL) {////
                        if (*(current2220->name) == *missing_dad) {///
                            
                            temp1->space =  current2220->space;///
                            temp1->sizetype_name = missing_dad;//
                            

                        }
                        current2220 = current2220->next;
                    }
                    Spec_array* current222 = head_Spec_array; // Initialize current.
                    while (current222 != NULL) {
                        if (*(current222->name) == *missing_dad) {
                            temp1->points = current222;
                            temp1->space = current222->space;
                            temp1->sizetype_name = missing_dad;

                        }
                        current222 = current222->next;
                    }

                    Record* current301 = head; // Initialize current.
                    while (current301 != NULL) {
                        if (*(current301->name) == *missing_dad) {
                            
                            temp1->sizetype_name = missing_dad;
                            
                        }
                        current301 = current301->next;
                    }
                    missing_dad = NULL;
                }
                
                temp1->size = 1;
                
            }
            if (in_arraytype == 0 && in_adresstype == 0 ) {
                if (flag_in_st_no_arr) {
                    Variable* current2222 = first; // Initialize current.
                    while (current2222 != NULL) {
                        if (*(current2222->name) == *universal_name) {
                           
                            temp1->size = current2222->size;
                           
                            temp1->size_point = current2222->size_point;
                            temp1->space = current2222->space;
                            temp1->points = current2222->points;
                            temp1->sizetype_name = current2222->sizetype_name;
                            
                        }
                        current2222 = current2222->next;
                        
                    }
                    flag_in_st_no_arr = false;
                }
            }





            
            temp1->next = NULL;
            if (first == NULL) { //list is empty

                first = last = temp1;
            }
            else {
                last->next = temp1;
                last = temp1;
            }
        }
      
        Dimensions* temp5=the_dimension_start;
        Dimensions* temp3=the_dimension_start;
        Spec_array* temp4;
        if (in_arraytype == 1) {
            flag_from_arrayvariable = true;
            int subpart = 1;
            int the_subpart = 0;
           
            if (temp5 != NULL) {
               for (temp5; temp5 != NULL; temp5=temp5->next) {
                   if (temp5->next != NULL) {
                       for (temp3 = temp5->next; temp3 != NULL; temp3=temp3->next) {
                                
                           subpart *= temp3->di;
                       }
                   }
                       
                   the_subpart += temp5->li * subpart;
                   
                  
                   subpart = 1;
               }
               the_subpart *= arraysize;
            }
                
            
            temp4 = (Spec_array*)malloc(sizeof(Spec_array)); //dynamic allocation for the new item at the tab
            if (temp4 == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
            }
            
            temp4->start = the_dimension_start;
            temp4->name = name_;
            temp4->subpart = the_subpart;
            
            temp4->counter_dim = counter_for_dims;
            counter_for_dims = 0;
            if (flag_from_st) {
                temp4->array_adress = addressbeg - 1;
            }
            else{
                temp4->array_adress = addressbeg;
            }
           
            addressbeg += SUM_OF_DI * arraysize-1;
            ssp = addressbeg;
            
            temp4->array_sizetype = arraysize;
            temp4->sizetype_name = the_name_of_sizetype;
            temp4->size = SUM_OF_DI * arraysize;
           
           
            temp4->next = NULL;
            if (head_Spec_array == NULL) { //list is empty

                head_Spec_array = tail_Spec_array = temp4;
            }
            else {
                tail_Spec_array->next = temp4;
                tail_Spec_array = temp4;
            }
           
            SUM_OF_DI = 1;

        }
        if (flag_from_st && flag_from_arrayvariable) {
            temp4->father_adress = temp1->address;
            temp1->points = temp4;
            temp1->address = temp4->array_adress;
            temp1->size = temp4->size;
            temp1->sizetype_name = temp4->sizetype_name;
            temp1->space = temp4->space;
           
        }



        Record* temp2;
        if((in_recordlist && (in_arraytype==0))|| (flag_array_rec)||(in_adresstype && in_recordlist)){
            
            doing_record=true;
            temp2 = (Record*)malloc(sizeof(Record)); //dynamic allocation for the new item at the tab
            if (temp2 == NULL) {
                printf("Memory allocation failed!\n");
                 exit(1);
            }
           



            temp2->name = name_;
            temp2->address = addressbeg;
            
            temp2->space = (temp2->address) - (last_record_label_add);
     
            
            temp2->size = 1;
            if (in_adresstype && in_recordlist) {
                if (flag_found_dad != true) {
                    temp2->size_point = -1;
                    
                }
                else {
                    flag_found_dad = false;
                }
                temp2->size = 1;
                temp2->size_point = pointer_size;
               
                if (missing_dad != NULL ) {
                    Spec_array* current2222 = head_Spec_array; // Initialize current.
                    while (current2222 != NULL) {
                        
                        if (*(current2222->name) == *missing_dad) {
                            
                            temp2->arr = current2222;
                            temp2->sizetype_name = missing_dad;///
                            
                            
                        }
                        current2222 = current2222->next;
                        
                    }

                    Variable* current2220 = first; // Initialize current.////
                    while (current2220 != NULL) {////
                        if (*(current2220->name) == *missing_dad) {///
                            temp2->sizetype_name = missing_dad;//
                        }
                        current2220 = current2220->next;
                    }
                    Record* current301 = head; // Initialize current.
                    while (current301 != NULL) {
                        if (*(current301->name) == *missing_dad) { 
                            temp2->sizetype_name = missing_dad;
                        }
                        current301 = current301->next;
                    }

                    missing_dad = NULL;
                }

                
            }
            
            if (in_arraytype == 0 && in_adresstype == 0) {
                if (flag_in_st_no_arr) {
                    Variable* current2222 = first; // Initialize current.
                    while (current2222 != NULL) {
                        if (*(current2222->name) == *universal_name) {
                            temp2->size = current2222->size;
                            temp2->size_point = current2222->size_point;
                            
                            temp2->arr = current2222->points;
                            
                        }
                        current2222 = current2222->next;
                        
                    }
                }
                flag_in_st_no_arr = false;
            }
            
           
            Varsize = 1;
            
            addressbeg += temp2->size;
            ssp = addressbeg;
             temp2->next = NULL;
             if (head == NULL) { //list is empty

                head = tail = temp2;
             }
             else {
                 tail->next = temp2;
                 tail = temp2;
             }
        }
        
        if (in_arraytype && in_recordlist) {
            temp2->arr = temp4;
            temp2->address = temp4->array_adress;
            temp2->size= temp4->size;
            temp4->space = (temp4->array_adress) - (last_record_label_add);
            temp2->space = temp4->space;
            temp2->sizetype_name = temp4->name;/////
            record_size += temp4->size;
           

        }

        
        ssp = addressbeg;
        
        in_simpletype = false;
        in_recordlist = false;
        in_recordtype = false;
        in_arraytype = false;
        in_adresstype = false;
        flag_array_rec = false;
        flag_from_arrayvariable = false;
        flag_from_st = false;
        flag_clone_array = false;
        found = false;
        flag_in_st_no_arr = false;
        flag_in_records = false;
        flag_found_dad = false;

        if (by_ref || !by_ref) {
           
            Record* current1 = head; // Initialize current.
            while (current1 != NULL) {
                if (*(current1->name) == *name_) {
                    if(by_ref)
                         current1->value_ref = 1;
                    current1->my_func_name = this_dad_name;
                }
                current1 = current1->next;
            }
            Variable* current2 = first; // Initialize current.
            while (current2 != NULL) {
                if (*(current2->name) == *name_) {  
                    if (by_ref)
                        current2->value_ref = 1;
                    current2->my_func_name = this_dad_name;
                }
                current2 = current2->next;
            }
            Spec_array* current3 = head_Spec_array; // Initialize current.
            while (current3 != NULL) {
                if (*(current3->name) == *name_) {
                    if (by_ref)
                        current3->value_ref = 1;
                    current3->my_func_name = this_dad_name;
                }
                current3 = current3->next;
            }
            Func* current4 = head_Func; // Initialize current.
            while (current4 != NULL) {
                if (*(current4->name) == *name_) { 
                    if (by_ref)
                         current4->value_ref = 1;
                }
                current4 = current4->next;
            }
        }
        
    }

    virtual Object* clone() const { return new VariableDeclaration(*this); }

private:
    Object* type_;
    string* name_;
};

class Parameter : public Object {
public:
    Parameter(Object* type, const char* name) : type_(type) {
        assert(type_);
        name_ = new string(name);
    }

    Parameter(const Parameter& p) {
        type_ = p.type_->clone();
        name_ = new string(*p.name_);
    }

    virtual ~Parameter() {
        if (type_) delete type_;
        delete name_;
    }

    void print(ostream& os) {
        printWayOfPassing(os);
        os << "Parameter name :" << *name_ << endl;
        assert(type_);
        type_->print(os);
    }
    void pcodegen(ostream& os) {
        printWayOfPassing(os);
        assert(type_);
        in_var_dec = true;
        in_parametr = true;
        string* temp_name = this_name_of_func;
        string* temp_dad_name = dad_name;
        this_name_of_func = name_;
        dad_name = name_;
     
        type_->pcodegen(os);

        this_name_of_func = temp_name;
       
        dad_name = temp_dad_name;





       
        in_parametr = false;
       
        in_var_dec = false;
        Variable* temp1;
        if ((in_recordlist == 0 || (in_adresstype == 1 && in_recordlist == 0)) && !flag_my_func_is_parametr) {
            flag_from_st = true;
            
            temp1 = (Variable*)malloc(sizeof(Variable)); //dynamic allocation for the new item at the tab
            if (temp1 == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
            }
            temp1->name = name_;

            if (doing_record) {//was before
                temp1->address = add_of_rec;

                last_record_label_add = add_of_rec;
                doing_record = false;
            }
            else {
                temp1->address = addressbeg++;
                if (we_came_from_addition_to_address) {
                    
                    we_came_from_addition_to_address = false;
                    addressbeg += size_to_add_to_address - 1;
                    
                }
                ssp = addressbeg;
            }
            temp1->size = Varsize;
            if (in_adresstype == 0 && in_arraytype == 0 && in_simpletype == 0) {
                
                temp1->size = record_size;
               
                par_size += record_size - 1;
                Record* current00 = head;
                while (current00 != NULL) {
                    if (current00->size_point == -1)
                    {
                        current00->size_point = record_size;
                    }

                    current00 = current00->next;
                }

            }

            if (in_adresstype) {
                temp1->size_point = pointer_size;
                if (missing_dad != NULL) {

                    Variable* current2220 = first; // Initialize current.////
                    while (current2220 != NULL) {////
                        if (*(current2220->name) == *missing_dad) {///
                           
                            temp1->space = current2220->space;///
                            temp1->sizetype_name = missing_dad;//
                            

                        }
                        current2220 = current2220->next;
                    }
                    Spec_array* current222 = head_Spec_array; // Initialize current.
                    while (current222 != NULL) {
                        if (*(current222->name) == *missing_dad) {
                            temp1->points = current222;
                            temp1->space = current222->space;
                            temp1->sizetype_name = missing_dad;

                        }
                        current222 = current222->next;
                    }

                    Record* current301 = head; // Initialize current.
                    while (current301 != NULL) {
                        if (*(current301->name) == *missing_dad) {
                            temp1->sizetype_name = missing_dad;
                        }
                        current301 = current301->next;
                    }
                    missing_dad = NULL;
                }

                temp1->size = 1;

            }
            if (in_arraytype == 0 && in_adresstype == 0) {
                if (flag_in_st_no_arr) {
                   
                    Variable* current2222 = first; // Initialize current.
                    while (current2222 != NULL) {
                        if (*(current2222->name) == *universal_name) {
                            temp1->size = current2222->size;
                            par_size += temp1->size - 1;
                            temp1->size_point = current2222->size_point;
                            temp1->space = current2222->space;
                            temp1->points = current2222->points;
                            temp1->sizetype_name = current2222->sizetype_name;

                        }
                        current2222 = current2222->next;

                    }
                    flag_in_st_no_arr = false;
                }
            }




            par_size++;
            
            temp1->next = NULL;
            if (first == NULL) { //list is empty

                first = last = temp1;
            }
            else {
                last->next = temp1;
                last = temp1;
            }
        }
        
        Dimensions* temp5 = the_dimension_start;
        Dimensions* temp3 = the_dimension_start;
        Spec_array* temp4;
        if (in_arraytype == 1) {
            flag_from_arrayvariable = true;
            int subpart = 1;
            int the_subpart = 0;

            if (temp5 != NULL) {
                for (temp5; temp5 != NULL; temp5 = temp5->next) {
                    if (temp5->next != NULL) {
                        for (temp3 = temp5->next; temp3 != NULL; temp3 = temp3->next) {

                            subpart *= temp3->di;
                        }
                    }

                    the_subpart += temp5->li * subpart;


                    subpart = 1;
                }
                the_subpart *= arraysize;
            }


            temp4 = (Spec_array*)malloc(sizeof(Spec_array)); //dynamic allocation for the new item at the tab
            if (temp4 == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
            }

            temp4->start = the_dimension_start;
            temp4->name = name_;
            temp4->subpart = the_subpart;

            temp4->counter_dim = counter_for_dims;
            counter_for_dims = 0;
            if (flag_from_st) {
                temp4->array_adress = addressbeg - 1;
            }
            else {
                temp4->array_adress = addressbeg;
            }

            addressbeg += SUM_OF_DI * arraysize - 1;
            ssp = addressbeg;
            temp4->array_sizetype = arraysize;
            temp4->sizetype_name = the_name_of_sizetype;
            temp4->size = SUM_OF_DI * arraysize;


            temp4->next = NULL;
            if (head_Spec_array == NULL) { //list is empty

                head_Spec_array = tail_Spec_array = temp4;
            }
            else {
                tail_Spec_array->next = temp4;
                tail_Spec_array = temp4;
            }

            SUM_OF_DI = 1;

        }
        if (flag_from_st && flag_from_arrayvariable) {
            temp4->father_adress = temp1->address;
            temp1->points = temp4;
            temp1->address = temp4->array_adress;
            temp1->size = temp4->size;
            temp1->sizetype_name = temp4->sizetype_name;
            temp1->space = temp4->space;

        }



        Record* temp2;
        if ((in_recordlist && (in_arraytype == 0)) || (flag_array_rec) || (in_adresstype && in_recordlist)) {

            doing_record = true;
            temp2 = (Record*)malloc(sizeof(Record)); //dynamic allocation for the new item at the tab
            if (temp2 == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
            }




            temp2->name = name_;
            temp2->address = addressbeg;

            temp2->space = (temp2->address) - (last_record_label_add);


            temp2->size = 1;
            if (in_adresstype && in_recordlist) {
                if (flag_found_dad != true) {
                    temp2->size_point = -1;

                }
                else {
                    flag_found_dad = false;
                }
                temp2->size = 1;
                temp2->size_point = pointer_size;

                if (missing_dad != NULL) {
                    Spec_array* current2222 = head_Spec_array; // Initialize current.
                    while (current2222 != NULL) {

                        if (*(current2222->name) == *missing_dad) {
                            dl;
                            temp2->arr = current2222;
                            temp2->sizetype_name = missing_dad;///

                            
                        }
                        current2222 = current2222->next;

                    }

                    Variable* current2220 = first; // Initialize current.////
                    while (current2220 != NULL) {////
                        if (*(current2220->name) == *missing_dad) {///                          
                            temp2->sizetype_name = missing_dad;//                          
                        }
                        current2220 = current2220->next;
                    }
                    Record* current301 = head; // Initialize current.
                    while (current301 != NULL) {
                        if (*(current301->name) == *missing_dad) {                         
                            temp2->sizetype_name = missing_dad;                           
                        }
                        current301 = current301->next;
                    }

                    missing_dad = NULL;
                }


            }

            if (in_arraytype == 0 && in_adresstype == 0) {
                if (flag_in_st_no_arr) {
                    Variable* current2222 = first; // Initialize current.
                    while (current2222 != NULL) {
                        if (*(current2222->name) == *universal_name) {
                            temp2->size = current2222->size;
                            temp2->size_point = current2222->size_point;

                            temp2->arr = current2222->points;

                        }
                        current2222 = current2222->next;

                    }
                }
                flag_in_st_no_arr = false;
            }

            
            Varsize = 1;

            addressbeg += temp2->size;
            par_size++;
            temp2->next = NULL;
            if (head == NULL) { //list is empty

                head = tail = temp2;
            }
            else {
                tail->next = temp2;
                tail = temp2;
            }
        }

        if (in_arraytype && in_recordlist) {
            temp2->arr = temp4;
            temp2->address = temp4->array_adress;
            temp2->size = temp4->size;
            temp4->space = (temp4->array_adress) - (last_record_label_add);
            temp2->space = temp4->space;
            temp2->sizetype_name = temp4->name;/////
            record_size += temp4->size;
            par_size + temp2->size;

        }
        Func* user1 = head_Func;
        if (flag_my_func_is_parametr){
            
            user1 = (Func*)malloc(sizeof(Func)); //dynamic allocation for the new item at the tab
            if (user1 == NULL) {
                printf("Memory allocation failed!\n");
                exit(1);
            }
            user1->name = name_;
            user1->as_para = 1;
            user1->size = 2;
            user1->address = addressbeg;
            addressbeg += 2;
            
            Func* just_temp = head_Func;
            while (just_temp) {
                if (*(just_temp->name) == *this_name_of_func) {
                    user1->here = just_temp->here;
                }
                just_temp = just_temp->next;
            }
            
            user1->my_func = this_dad_name;
            if (in_funcdec)
                user1->return_value = 1;
            user1->next = NULL;
            if (head_Func == NULL) { //list is empty

                head_Func = tail_Func = user1;
            }
            else {
                tail_Func->next = user1;
                tail_Func = user1;
            }
            
        }
       
        ssp = addressbeg;
       
        
        in_simpletype = false;
        in_recordlist = false;
        in_recordtype = false;
        in_arraytype = false;
        in_adresstype = false;
        flag_array_rec = false;
        flag_from_arrayvariable = false;
        flag_from_st = false;
        flag_clone_array = false;
        found = false;
        flag_in_st_no_arr = false;
        flag_in_records = false;
        flag_found_dad = false;


        bool ref_lately = false;
        int what_temp = 1;
        int temp_size = 0;
        Func* current4 = head_Func;
        if (by_ref || !by_ref) {
            
            Record* current1 = head; // Initialize current.
            while (current1 != NULL) {
                if (*(current1->name) == *name_) {   
                    what_temp = 2;
                    temp_size = current1->size;
                    if (by_ref) {
                        current1->value_ref = 1;
                        ref_lately = true;
                    }
                    current1->my_func_name = this_dad_name;                   
                }
                current1 = current1->next;
            }
            Variable* current2 = first; // Initialize current.
            while (current2 != NULL) {
                if (*(current2->name) == *name_) {                  
                    what_temp = 1;
                    temp_size = current2->size;
                    if (by_ref) {
                        current2->value_ref = 1;
                        ref_lately = true;
                    }
                    current2->my_func_name= this_dad_name;                   
                }
                current2 = current2->next;
            }
            Spec_array* current3 = head_Spec_array; // Initialize current.
            while (current3 != NULL) {
                if (*(current3->name) == *name_) {                   
                    what_temp = 4;
                    temp_size = current3->size;
                    if (by_ref) {
                        current3->value_ref = 1;
                        ref_lately = true;
                    }
                    
                    current3->my_func_name = this_dad_name;                   
                }
                current3 = current3->next;
            }
             // Initialize current.
            Func* current44 = head_Func;
            while (current44 != NULL) {
                if (*(current44->name) == *name_) {                  
                    what_temp = 5;
                    current4 = current44;
                    temp_size = current44->size;
                    current44->as_para = flag_my_func_is_parametr;
                    flag_my_func_is_parametr = false;
                    if (by_ref) {
                        current44->value_ref = 1;
                        ref_lately = true;
                    }                  
                }
                current44 = current44->next;
            }
        }
        
        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        paralist* temp123;
        temp123 = (paralist*)malloc(sizeof(paralist)); //dynamic allocation for the new item at the tab
        if (temp123 == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        temp123->name = name_;
        temp123->by_ref = ref_lately;
        ref_lately = false;
        if (what_temp == 1) {
            temp123->size = temp1->size;
        }
        else if (what_temp == 2) {
            temp123->size = temp2->size;
        }
        else if (what_temp == 4) {
            temp123->size = temp4->size;
        }
        else {
            
            temp123->size = current4->size;
        }
        
        global_size_for_parametrs += temp123->size;
        temp123->next = NULL;

       if (head_para == NULL) { //list is empty

           head_para = tail_para = temp123;
       }
       else {
           tail_para->next = temp123;
           tail_para = temp123;
       }


       ssp = addressbeg;


        /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    }
protected:
    virtual void printWayOfPassing(ostream& os) const = 0;

private:
    Object* type_;
    string* name_;
};

class ByReferenceParameter : public Parameter {
public:
    ByReferenceParameter(Object* type, const char* name) : Parameter(type, name) {}
    virtual Object* clone() const { return new ByReferenceParameter(*this); }
protected:
    void printWayOfPassing(ostream& os) const {
        
        by_ref = true;
        
    }
};

class ByValueParameter : public Parameter {
public:
    ByValueParameter(Object* type, const char* name) : Parameter(type, name) {}
    virtual Object* clone() const { return new ByValueParameter(*this); }
protected:
    void printWayOfPassing(ostream& os) const {
        
        by_ref = 0;
      
    }
};

class ParameterList : public Object {
public:
    ParameterList(Object* formal) : formal_(formal), formal_list_(NULL) { assert(formal_); }
    ParameterList(Object* formal, Object* formal_list) : formal_(formal), formal_list_(formal_list) { assert(formal_ && formal_list_); }

    ParameterList(const ParameterList& pl) {
        formal_ = pl.formal_->clone();
        formal_list_ = pl.formal_list_->clone();
    }

    virtual ~ParameterList() {
        if (formal_) delete formal_;
        if (formal_list_) delete formal_list_;
    }

    void print(ostream& os) {
        os << "Node name : ParameterList" << endl;
       
        assert(formal_);
        formal_->print(os);
        //changed between them
        if (formal_list_) {
            formal_list_->print(os);
        }
    }
    void pcodegen(ostream& os) {
        //print ssp sep name and all
        //if from func or procud or program print ssp sep
        
        assert(formal_);
        if (in_funcdec || in_prodcdec || in_program) {//doing a function {
            
            Func* temp = head_Func;
            os << *dad_name << ":" << endl;
           
            os << "ssp " << ssp << endl;
            os << "sep 50" << endl;
            os << "ujp " << *dad_name << "_begin" << endl;
          
            ssp = 5;
            addressbeg = 5;
            in_funcdec = in_prodcdec = in_program = 0;
        }


        in_paramlist = 1;
        formal_->pcodegen(os);//paramater
        in_paramlist = 0;

        if (formal_list_) {//we changed between them
            formal_list_->pcodegen(os);
        }


    }
    virtual Object* clone() const { return new ParameterList(*this); }

private:
    Object* formal_;
    Object* formal_list_;
};

class FunctionDeclaration : public Declaration {
public:
    FunctionDeclaration(Object* type, Object* block, const char* name) : type_(type), block_(block), formal_list_(NULL) {
        assert(type_ && block_);
        name_ = new string(name);
    }

    FunctionDeclaration(Object* type, Object* formal_list, Object* block, const char* name) : type_(type), formal_list_(formal_list), block_(block) {
        assert(type_ && formal_list_ && block_);
        name_ = new string(name);
    }

    virtual ~FunctionDeclaration() {
        if (type_) delete type_;
        if (block_) delete block_;
        if (formal_list_) delete formal_list_;
        if (name_) delete name_;
    }

    FunctionDeclaration(const FunctionDeclaration& fd) {
        type_ = fd.type_->clone();
        block_ = fd.block_->clone();
        formal_list_ = fd.formal_list_->clone();
        name_ = new string(*fd.name_);
    }

    void print(ostream& os) {
        os << "Node name : FunctionDeclaration. Func name is: " << *name_ << endl;
        assert(type_ && block_);
        type_->print(os);
        if (formal_list_) {
            formal_list_->print(os);
        }
        block_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(type_ && block_);
        this_dad_name = name_;
        type_->pcodegen(os);
        
        //par_size = 5;
        int temp_dep = dep;
        global_size_for_parametrs = 0;
        if (formal_list_) {
            formal_list_->pcodegen(os);
        }


        Func* temp1;
        temp1 = (Func*)malloc(sizeof(Func)); //dynamic allocation for the new item at the tab
        if (temp1 == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        temp1->name_of_dad = dad_name;
        int temp2 = in_funcdec;
        in_funcdec = true;

        int temp3 = in_program;
        in_program = false;

        the_end = true;

        
        string* temp_name = this_name_of_func;
        string* temp_dad_name = dad_name;
        this_name_of_func = name_;
        dad_name = name_;
        int temp4 = flag_for_func_prod;
        flag_for_func_prod = true;

        
        temp1->here = head_para;
        head_para = NULL;
        tail_para = NULL;
        temp1->para_size = global_size_for_parametrs;
        temp1->name = name_;
        temp1->depth = dep++;
       
        temp1->return_value = 1;
        temp1->ssp = par_size;
       
        temp1->next = NULL;
        if (head_Func == NULL) { //list is empty

            head_Func = tail_Func = temp1;
        }
        else {
            tail_Func->next = temp1;
            tail_Func = temp1;
        }

     
        block_->pcodegen(os);
        
        
                                                     dep = temp_dep;
        this_name_of_func = temp_name;
        flag_for_func_prod = temp4;
        dad_name = temp_dad_name;
        in_prodcdec = temp2;
        in_program = temp3;
        os << "retf" << endl;
       
    }
    virtual Object* clone() const { return new FunctionDeclaration(*this); }

private:
    Object* type_;
    Object* block_;
    Object* formal_list_;
    string* name_;
};

class ProcedureDeclaration : public Declaration {
public:
    ProcedureDeclaration(Object* block, const char* name) : formal_list_(NULL), block_(block) {
        assert(block_);
        name_ = new string(name);
    }

    ProcedureDeclaration(Object* formal_list, Object* block, const char* name) : formal_list_(formal_list), block_(block) {
        assert(formal_list_ && block_);
        name_ = new string(name);
    }

    virtual ~ProcedureDeclaration() {
        if (block_) delete block_;
        if (formal_list_) delete formal_list_;
        if (name_) delete name_;
    }

    ProcedureDeclaration(const ProcedureDeclaration& pd) {
        block_ = pd.block_->clone();
        formal_list_ = pd.formal_list_->clone();
        name_ = new string(*pd.name_);
    }

    void print(ostream& os) {
        os << "Node name : ProcedureDeclaration. Proc name is: " << *name_ << endl;
        assert(block_);
       
       
        if (formal_list_) {
            
            formal_list_->print(os);
            
        }
        
        block_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(block_);
        this_dad_name = name_;
       
        global_size_for_parametrs = 0;



        int temp_dep = dep;

        if (formal_list_) {//pararmetrs of functions
            formal_list_->pcodegen(os);
        }
       
        Func* temp1;
        temp1 = (Func*)malloc(sizeof(Func)); //dynamic allocation for the new item at the tab
        if (temp1 == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }
        int temp2 = in_prodcdec;
        in_prodcdec = true;
       
        int temp3 = in_program;
        in_program = false;

        the_end = true;

        temp1->name_of_dad = dad_name;
       
        string* temp_name = this_name_of_func;
        string* temp_dad_name = dad_name;
        this_name_of_func = name_;
        dad_name = name_;
        int temp4 = flag_for_func_prod;
        flag_for_func_prod = true;

        temp1->here = head_para;
        head_para = NULL;
        tail_para = NULL;
        temp1->para_size = global_size_for_parametrs;
       
        temp1->name = name_;
        temp1->depth = dep++;
        
        temp1->return_value = 0;
        temp1->ssp = par_size;
       
        temp1->next = NULL;
        if (head_Func == NULL) { //list is empty

            head_Func = tail_Func = temp1;
        }
        else {
            tail_Func->next = temp1;
            tail_Func = temp1;
        }
       
        block_->pcodegen(os);
        dep = temp_dep;
       
       
        this_name_of_func = temp_name;
        flag_for_func_prod = temp4;
        dad_name = temp_dad_name;
        in_prodcdec = temp2;
        in_program = temp3;
        
      
        os << "retp" << endl;
        
    }
    virtual Object* clone() const { return new ProcedureDeclaration(*this); }

private:
    Object* block_;
    Object* formal_list_;
    string* name_;
};

class DeclarationList : public Object {
public:
    DeclarationList(Object* decl) : decl_(decl), decl_list_(NULL) {
        assert(decl_);
      
    }
    DeclarationList(Object* decl_list, Object* decl) : decl_list_(decl_list), decl_(decl) { assert(decl_list_ && decl); }

    DeclarationList(const DeclarationList& dl) {
        decl_ = dl.decl_->clone();
        decl_list_ = dl.decl_list_->clone();
    }

    virtual ~DeclarationList() {
        if (decl_) delete decl_;
        if (decl_list_) delete decl_list_;
    }

    void print(ostream& os) {
        os << "Node name : DeclarationList" << endl;
        if (decl_list_) {
            decl_list_->print(os);
        }
        assert(decl_);
        decl_->print(os);
    }
    void pcodegen(ostream& os) {
        if (decl_list_) {
            decl_list_->pcodegen(os);
        }
        assert(decl_);
        
        decl_->pcodegen(os);
       
    }
    virtual Object* clone() const { return new DeclarationList(*this); }

private:
    Object* decl_;
    Object* decl_list_;
};

class Block : public Object {
public:
    Block(Object* stat_seq) : stat_seq_(stat_seq), decl_list_(NULL) { assert(stat_seq_); }
    Block(Object* decl_list, Object* stat_seq) : decl_list_(decl_list), stat_seq_(stat_seq) { assert(decl_list_ && stat_seq_); }

    Block(const Block& b) {
        decl_list_ = b.decl_list_->clone();
        stat_seq_ = b.stat_seq_->clone();
    }

    virtual ~Block() {
        if (stat_seq_) delete stat_seq_;
        if (decl_list_) delete decl_list_;
    }

    void print(ostream& os) {
        os << "Node name : Begin" << endl;
        if (decl_list_) {
            decl_list_->print(os);
        }
        assert(stat_seq_);
        stat_seq_->print(os);
    }
    void pcodegen(ostream& os) {
       
        
        if (decl_list_) {//mshtnem tb3at program
            decl_list_->pcodegen(os);
        }

        
        assert(stat_seq_);
        if (the_end) {
            the_end = false;
            //int ssp = 0;
            Func* temp = head_Func;
            os << *dad_name << ":" << endl;
           
            os << "ssp " << ssp << endl;
            os << "sep 50" << endl;
            ssp = 5;
            addressbeg = 5;
            os << "ujp " << *dad_name << "_begin" << endl;
           
        }
        os << *dad_name << "_begin:" << endl;
       

        stat_seq_->pcodegen(os);
       
    }

    virtual Object* clone() const { return new Block(*this); }

private:
    Object* decl_list_;
    Object* stat_seq_;
};

class Program : public Object {
public:
    Program(Object* block, const char* str) : block_(NULL) {
        block_ = dynamic_cast<Block*>(block);
        assert(block_);
        name_ = new string(str);
    }

    Program(const Program& prog) {
        block_ = dynamic_cast<Block*>(prog.block_->clone());
        assert(block_);
        name_ = new string(*prog.name_);
    }

    virtual ~Program() {
        if (block_) delete block_;
        delete name_;
    }

    void print(ostream& os) {
        os << "Node name : Root/Program. Program name is: " << *name_ << endl;
        assert(block_);
        block_->print(os);
    }
    void pcodegen(ostream& os) {
        assert(block_);
        this_dad_name = name_;
        in_program = true;
        Func* temp1;
        temp1 = (Func*)malloc(sizeof(Func)); //dynamic allocation for the new item at the tab
        if (temp1 == NULL) {
            printf("Memory allocation failed!\n");
            exit(1);
        }

        temp1->name = name_;
        temp1->name_of_dad = name_;
        temp1->depth = dep++;
        dad_name = name_;
        this_name_of_func = name_;
        temp1->next = NULL;
        if (head_Func == NULL) { //list is empty

            head_Func = tail_Func = temp1;
        }
        else {
            tail_Func->next = temp1;
            tail_Func = temp1;
        }
        
        block_->pcodegen(os);
        
        os << "stp" << endl;
    }
    virtual Object* clone() const { return new Program(*this); }

private:
    Block* block_;
    string* name_;
};





#endif //AST_H
//ast.h
//Displaying ast.h.