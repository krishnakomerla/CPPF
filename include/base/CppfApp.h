#ifndef CPPFAPP_H
#define CPPFAPP_H

#include "MooseApp.h"

class CppfApp;

template<>
InputParameters validParams<CppfApp>();

class CppfApp : public MooseApp
{
public:
  CppfApp(InputParameters parameters);
  virtual ~CppfApp();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* CPPFAPP_H */
