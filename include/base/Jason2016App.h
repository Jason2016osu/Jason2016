#ifndef JASON2016APP_H
#define JASON2016APP_H

#include "MooseApp.h"

class Jason2016App;

template<>
InputParameters validParams<Jason2016App>();

class Jason2016App : public MooseApp
{
public:
  Jason2016App(InputParameters parameters);
  virtual ~Jason2016App();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* JASON2016APP_H */
