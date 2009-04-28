TestUtils = {
  element: $("#asset_1"),
  tinyTab: function() {
    return new TinyTab('#assets_widget', '#panels');
  },
  reset: function() {
    $("#tab_attached_assets").hide();
  }
}

module("jQuery exist");
test("should verify existence of elements", function() {
  ok($("#assets_widget").exist(), "should verify the existence of #assets_widget");
  ok(!$("#unexistent").exist(),   "shouldn't verify the existence of #unexistent");
});

module("ASSET WIDGET");

test("should return site id", function() {
  ok(false, "flunked");
});

test("should return asset id", function() {
  equals(AssetWidget.assetId(TestUtils.element), "1");
});

test("should return member id", function() {
  ok(false, "flunked");
});

test("should return assets url", function() {
  $.extend(AssetWidget, { siteId: function() {return "1";} });
  equals(AssetWidget.assetsUrl(), '/admin/sites/1/assets');
});

test("should guess if it is an edit", function() {
  ok(false, "flunked");
});

test("should return collection url", function() {
  equals(AssetWidget.collectionUrl(TestUtils.element), '/admin/sites/1/assets/1/contents');
});

test("should return member url", function() {
  $.extend(AssetWidget, { memberId: function() {return "1";} });
  equals(AssetWidget.memberUrl(TestUtils.element), '/admin/sites/1/assets/1/contents/1');
});

test("should attach asset", function() {
  ok(false, "flunked: TODO allow WEBrick to accept POST reqs");
  // $.extend(AssetWidget, { collectionUrl: function(element) { return "/adva_assets/assets/controller";} });
  // ok(AssetWidget.attachAsset(TestUtils.element), "should attach asset");
});

test("should detach asset", function() {
  ok(false, "flunked: TODO allow WEBrick to accept POST reqs");
  // $.extend(AssetWidget, { collectionUrl: function(element) { return "/adva_assets/assets/controller";} });
  // ok(AssetWidget.detachAsset($("#asset_2")), "should detach asset");
});

test("should verify if it is attached", function() {
  ok(!AssetWidget.isAttached(TestUtils.element), "It should not be attached (no attached_asset_1 element).");
  ok(AssetWidget.isAttached($("#asset_2")), "It should be attached (attached_asset_2 element).");
});

test("should update selected", function() {
  AssetWidget.updateSelected();
  ok($("#tab_attached_assets").is(":visible"), "should be visible");
  ok(!$(".latest_asset").hasClass("selected"),  "should not be selected");
  ok(!$(".bucket_asset").hasClass("selected"),  "should not be selected");
  ok($("#latest_asset_2").hasClass("selected"), "should be selected");
  ok($("#bucket_asset_2").hasClass("selected"), "should be selected");
});

test("should update selected tab", function() {
  AssetWidget.updateSelectedTab(false);
  ok(!$("#tab_attached_assets").is(":visible"), "should not be visible");
  ok(!$("#attached_assets").is(":visible"),     "should not be visible");

  AssetWidget.updateSelectedTab(true);
  ok($("#tab_attached_assets").is(":visible"), "should be visible");
});

test("should show selected tab", function() {
  TestUtils.reset();
  AssetWidget.showSelectedTab();
  ok($("#tab_attached_assets").is(":visible"), "should be visible");
});

test("should hide selected tab", function() {
  AssetWidget.hideSelectedTab();
  ok(!$("#tab_attached_assets").is(":visible"), "should not be visible");
  ok(!$("#attached_assets").is(":visible"),     "should not be visible");
});

test("should update selected assets", function() {
  AssetWidget.updateSelectedAssets([1]);
  ok(!$(".latest_asset").hasClass("selected"),  "should not be selected");
  ok(!$(".bucket_asset").hasClass("selected"),  "should not be selected");
  ok($("#latest_asset_1").hasClass("selected"), "should be selected");
  ok($("#bucket_asset_1").hasClass("selected"), "should be selected");
});

test("should return selected assets ids", function() {
  // same(AssetWidget.selectedAssetIds(), ["2"]);
  equals(AssetWidget.selectedAssetIds()[0], ["2"][0]);
});

test("should show attach tools", function() {
  $.extend(AssetWidget, {isEdit: function() { return true; }});
  AssetWidget.showAttachTools(1);
  ok($("#attach_1").is(":visible"), "should be visible");
  ok($("#detach_1").is(":visible"), "should be visible");
});

test("should hide attach tools", function() {
  AssetWidget.hideAttachTools(1);
  ok(!$("#attach_1").is(":visible"), "should not be visible");
  ok(!$("#detach_1").is(":visible"), "should not be visible");
});

test("should not perform search if query is missing", function() {
  ok(!$("#search_assets_spinner").is(":visible"), "spinner should not be visible");
  AssetWidget.search();
  ok(!$("#search_assets_spinner").is(":visible"), "spinner should not be visible");
});

test("should search", function() {
  $.extend(AssetWidget, { assetsUrl: function() { return "/adva_assets/assets/search";} });
  ok(!$("#search_assets_spinner").is(":visible"), "spinner should not be visible");
  AssetWidget.search("adva");
  ok($("#search_assets_spinner").is(":visible"), "spinner should be visible");
});

test("should upload", function() {
  AssetWidget.upload(TestUtils.element, "authenticityToken");
  ok($("#asset_upload_frame").exist(), "should create an iframe");
  ok(false, "flunked: TODO allow WEBrick to accept POST reqs");
});

module("TINY TAB");
test("should initialize", function() {
  tinyTab = TestUtils.tinyTab();
  // equals(tinyTab.tabs, $(".tabs").children());
  // equals(tinyTab.panels, $(".panel"));
  equals(tinyTab.tabs.length, 5);
  equals(tinyTab.panels.length, 1);
  ok($(tinyTab.panels[0]).is(":visible"), "first panel should be visible");
  ok($(tinyTab.tabs[0]).hasClass("selected"), "first panel should be selected")
});

test("should observe tabs clicks", function() {
  tinyTab = TestUtils.tinyTab();
  tab = $(tinyTab.tabs[3]);
  tab.click();
  ok(tab.hasClass("selected"), "should have 'selected' class");
});

test("should select tab", function() {
  tinyTab = TestUtils.tinyTab();
  tab = tinyTab.tabs[1];
  tinyTab.selectTab(tab);
  ok($(tab).hasClass("selected"), "should have 'selected' class");
});

test("should select first tab", function() {
  tinyTab = TestUtils.tinyTab();
  tinyTab.selectFirstTab();
  ok($(tinyTab.tabs[0]).hasClass("selected"), "should have 'selected' class");
});

test("should return selected tab", function() {
  tinyTab = TestUtils.tinyTab();
  tab = $(tinyTab.tabs[2]);
  $(".selected").removeClass("selected");
  tinyTab.selectTab(tab);
  equals(tinyTab.selectedTab().attr("id"), tab.attr("id"));
});