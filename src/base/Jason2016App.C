#include "Jason2016App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<Jason2016App>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

Jason2016App::Jason2016App(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  Jason2016App::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  Jason2016App::associateSyntax(_syntax, _action_factory);
}

Jason2016App::~Jason2016App()
{
}

// External entry point for dynamic application loading
extern "C" void Jason2016App__registerApps() { Jason2016App::registerApps(); }
void
Jason2016App::registerApps()
{
  registerApp(Jason2016App);
}

// External entry point for dynamic object registration
extern "C" void Jason2016App__registerObjects(Factory & factory) { Jason2016App::registerObjects(factory); }
void
Jason2016App::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void Jason2016App__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { Jason2016App::associateSyntax(syntax, action_factory); }
void
Jason2016App::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
