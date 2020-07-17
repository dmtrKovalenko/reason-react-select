describe("Country select", () => {
  beforeEach(() => {
    cy.server()
    cy.visit("http://localhost:3000")
  })

  it("Should open dropdown and show the countries list", () => {
    cy.findByLabelText("Select country").click()
    cy.focused().type("United") 

    cy.contains("United States")
  })

  it("Should select country by click", () => {
    cy.findByLabelText("Select country").click()
    cy.focused().type("United") 

    cy.contains("United States").click()
    cy.findByLabelText(/Selected country/).contains("United States")
  })

  it("Allows keyboard control", () => {
    cy.findByLabelText("Select country").type(" ", { force: true })

    cy.contains("Loading...").should('not.exist')

    cy.focused().type("Ukr")
    cy.focused().type("{enter}")

    cy.findByLabelText(/Selected country/).contains("Ukraine")
  })

  it("Should render proper flags", () => {
    cy.findByLabelText("Select country").click();

    cy.focused().type("Falkland")
    cy.contains("🇫🇰")
  })
})