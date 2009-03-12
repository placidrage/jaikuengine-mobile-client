/*
* ============================================================================
*  Name     : CDummyProjDocument from DummyProjDocument.h
*  Part of  : DummyProj
*  Created  : 13/04/2005 by Mike Howson
*  Implementation notes:
*     Initial content was generated by Series 60 AppWizard.
*  Version  :
*  Copyright: Penrillian
* ============================================================================
*/

// INCLUDE FILES
#include "DummyProjDocument.h"
#include "DummyProjAppUi.h"

// ================= MEMBER FUNCTIONS =======================

// constructor
CDummyProjDocument::CDummyProjDocument(CEikApplication& aApp)
: CAknDocument(aApp)    
    {
    }

// destructor
CDummyProjDocument::~CDummyProjDocument()
    {
    }

// EPOC default constructor can leave.
void CDummyProjDocument::ConstructL()
    {
    }

// Two-phased constructor.
CDummyProjDocument* CDummyProjDocument::NewL(
        CEikApplication& aApp)     // CDummyProjApp reference
    {
    CDummyProjDocument* self = new (ELeave) CDummyProjDocument( aApp );
    CleanupStack::PushL( self );
    self->ConstructL();
    CleanupStack::Pop();

    return self;
    }
    
// ----------------------------------------------------
// CDummyProjDocument::CreateAppUiL()
// constructs CDummyProjAppUi
// ----------------------------------------------------
//
CEikAppUi* CDummyProjDocument::CreateAppUiL()
    {
    return new (ELeave) CDummyProjAppUi;
    }

// End of File  
