/*********************************
 * Clase Usuario, que tiene los métodos relacionados con los usuarios
 * y las características del mismo.
 * 
 **********************************/
#include <iostream>
#include <fstream>
#include <string>

class Usuario  {
 public:
  Usuario() {}
  ~Usuario();

  void SetName(std::string nombre) {nombre_ = nombre;}
  void SetPasswd(std::string passwd)  { passwd_ = passwd;}

  bool CheckUser(std::string nombre);
  bool CheckPasswd(std::string passwd);

  bool AddName();
  bool AddPasswd();

  void WriteName(std::string new_name);
  void WritePasswd(std::string new_passwd);

  std::string GetName() {return nombre_;}

 private:
 std::string nombre_;
 std::string passwd_;
 std::fstream file_name_;
 std::fstream file_passwd_;
};
