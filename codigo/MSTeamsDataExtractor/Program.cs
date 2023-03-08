using Azure.Identity;
using Microsoft.Graph;
using Microsoft.Graph.TermStore;

namespace MSTeamsDataExtractor
{
  class Program
  {
    static async Task Main(string[] args)
    {
      var scopes = new[] { "User.Read", "Team.ReadBasic.All" , "EduRoster.ReadBasic" };

      // Multi-tenant apps can use "common",
      // single-tenant apps must use the tenant ID from the Azure portal
      var tenantId = "caca9011-7b6a-44de-861f-095a2ca883b7";

      // Value from app registration
      var clientId = "465ea0d4-3510-4173-9ccd-e42e967ef20e";

      // using Azure.Identity;
      var options = new InteractiveBrowserCredentialOptions
      {
        TenantId = tenantId,
        ClientId = clientId,
        AuthorityHost = AzureAuthorityHosts.AzurePublicCloud,
        // MUST be http://localhost or http://localhost:PORT
        // See https://github.com/AzureAD/microsoft-authentication-library-for-dotnet/wiki/System-Browser-on-.Net-Core
        RedirectUri = new Uri("http://localhost"),
      };

      // https://learn.microsoft.com/dotnet/api/azure.identity.interactivebrowsercredential
      var interactiveCredential = new InteractiveBrowserCredential(options);

      var graphClient = new GraphServiceClient(interactiveCredential, scopes);

      var classes = await graphClient.Education.Classes
        .Request()
        .GetAsync();

      foreach (var c in classes) {
        Console.WriteLine($"Title: {c.DisplayName}, ID: {c.Id}");
      }
      //  var joinedTeams = await graphClient.Teams["752e349e-9a55-4991-8c55-89b2fc9a8bb5"]
      //    .InstalledApps[""]
      //    .Me.JoinedTeams
      //    .Request()
      //    .GetAsync();

      //  // Output the assignment data
      //  foreach (var team in joinedTeams)
      //  {
      //    Console.WriteLine($"Title: {team.DisplayName}, ID: {team.Id}");
      //  }
      //  var misTeams = joinedTeams.Where(x => x.Id == "752e349e-9a55-4991-8c55-89b2fc9a8bb5" || x.Id == "5ef8a413-32dc-44ec-b47d-39576207cbd3\r\n").ToList();
      ////  var events = await graphClient.Groups["{group-id}"].Events
      ////.Request()
      ////.GetAsync();


    }
  }
}
