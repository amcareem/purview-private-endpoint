using System;
using System.Threading.Tasks;
using Azure;
using Azure.Core;
using Azure.Identity;
using Azure.ResourceManager;
using Azure.ResourceManager.Purview;
using Azure.ResourceManager.Purview.Models;

// Generated from example definition: specification/purview/resource-manager/Microsoft.Purview/stable/2021-07-01/examples/PrivateEndpointConnections_CreateOrUpdate.json
// this example is just showing the usage of "PrivateEndpointConnections_CreateOrUpdate" operation, for the dependent resources, they will have to be created separately.

// get your azure access token, for more details of how Azure SDK get your access token, please refer to https://learn.microsoft.com/en-us/dotnet/azure/sdk/authentication?tabs=command-line
TokenCredential cred = new DefaultAzureCredential();
// authenticate your client
ArmClient client = new ArmClient(cred);

// this example assumes you already have this PurviewPrivateEndpointConnectionResource created on azure
// for more information of creating PurviewPrivateEndpointConnectionResource, please refer to the document of PurviewPrivateEndpointConnectionResource
string subscriptionId = "34adfa4f-cedf-4dc0-ba29-b6d1a69ab345";
string resourceGroupName = "SampleResourceGroup";
string accountName = "account1";
string privateEndpointConnectionName = "privateEndpointConnection1";
ResourceIdentifier purviewPrivateEndpointConnectionResourceId = PurviewPrivateEndpointConnectionResource.CreateResourceIdentifier(subscriptionId, resourceGroupName, accountName, privateEndpointConnectionName);
PurviewPrivateEndpointConnectionResource purviewPrivateEndpointConnection = client.GetPurviewPrivateEndpointConnectionResource(purviewPrivateEndpointConnectionResourceId);

// invoke the operation
PurviewPrivateEndpointConnectionData data = new PurviewPrivateEndpointConnectionData()
{
    ConnectionState = new PurviewPrivateLinkServiceConnectionState()
    {
        Description = "Approved by johndoe@company.com",
        Status = PurviewPrivateLinkServiceStatus.Approved,
    },
};
ArmOperation<PurviewPrivateEndpointConnectionResource> lro = await purviewPrivateEndpointConnection.UpdateAsync(WaitUntil.Completed, data);
PurviewPrivateEndpointConnectionResource result = lro.Value;

// the variable result is a resource, you could call other operations on this instance as well
// but just for demo, we get its data from this resource instance
PurviewPrivateEndpointConnectionData resourceData = result.Data;
// for demo we just print out the id
Console.WriteLine($"Succeeded on id: {resourceData.Id}");